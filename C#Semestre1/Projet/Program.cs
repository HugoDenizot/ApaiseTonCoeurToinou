using Classes;
using Cryptage;
using Serialization;
using System;
using System.ComponentModel.DataAnnotations;
using System.Net.Mail;

namespace ConsoleApp1
{

    /// <summary>
    /// Cette class est la class qui sera exécuté en premier lors du lancement du programme. Elle contient
    /// la fonction main.
    /// </summary>
    public class Program
    {

        Dossier dossier_base = null;

        /// <summary>
        /// Cette fonction permet de créer un formulaire de création de Dossier.
        /// </summary>
        /// <param name="current">Prends en entrée le dossier actuel pour l'associer au parent du dossier créé </param>
        /// <returns>Retourne le nouveau dossier créé.</returns>
        public static Dossier demandeCreationDossier(Dossier current)
        {

            Console.ForegroundColor = ConsoleColor.White;
            string nom;
            Console.WriteLine("Donnez un nom de dossier:");
            nom = Console.ReadLine();
            return new Dossier(nom, current);
        }

        /// <summary>
        /// Cette fonction permet de retourner le dossier le plus haut de l'arborescence
        /// </summary>
        /// <returns>Retourne le dossier le plus haut de l'arborescence</returns>
        public Dossier getBase()
        {
            return dossier_base;
        }

        /// <summary>
        /// Cette fonction permet de créer un formulaire servant à créer un contact en demandant les renseignement
        /// à l'utilisateur.
        /// </summary>
        /// <returns>Retourne le contact créer par la fonction</returns>
        public static Contact demandeCreationContact()
        {
            string nom, prenom, societe, lien, mail;
            Lien lien_choisi = Lien.ami;
            MailAddress courriel;
            bool boucle = true, boucle2 = true;
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("Donnez le nom du contact:");
            nom = Console.ReadLine();
            Console.WriteLine("Donnez le prenom du contact:");
            prenom = Console.ReadLine();
            Console.WriteLine("Donnez le mail du contact:");
            mail = Console.ReadLine();
            while (boucle)
            {
                if (new EmailAddressAttribute().IsValid(mail))
                {

                    boucle = false;
                }
                else
                {
                    Console.WriteLine("Ceci n'est pas une adresse mail, redonnez en une :");
                    mail = Console.ReadLine();
                }
            }
            Console.WriteLine("Donnez le nom de la société du contact:");
            societe = Console.ReadLine();
            Console.WriteLine("Donnez un nom de lien entre: ami,collegue,relation,reseau");
            lien = Console.ReadLine();
            while (boucle2)
            {
                switch (lien.ToLower())
                {
                    case "relation":
                        lien_choisi = Lien.relation;
                        boucle2 = false;
                        break;
                    case "collegue":
                        lien_choisi = Lien.collegue;
                        boucle2 = false;
                        break;
                    case "ami":
                        lien_choisi = Lien.ami;
                        boucle2 = false;
                        break;
                    case "reseau":
                        lien_choisi = Lien.reseau;
                        boucle2 = false;
                        break;
                    default:
                        Console.WriteLine("Ceci n'est pas une proposition, choisissez entre: ami,collegue,relation,reseau");
                        lien = Console.ReadLine();
                        break;
                }
            }
            return new Contact(nom, prenom, lien_choisi, mail, societe);
        }

        /// <summary>
        /// Cette fonction contient tout le code nécessaire à l'éxécution du programme (menu, choix, etc). 
        /// </summary>
        private static void Main()
        {
            BinarySerialize dataBinary = new BinarySerialize();
            XMLSerialize dataXml = new XMLSerialize();
            CryptClass c = new CryptClass();
            string reponse;
            string rep;
            bool reussite;
            Dossier nouveau;
            Contact nouveauContact;
            Dossier current = null;
            Dossier dossier_base = null;


            bool loop = true;
            while (loop)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Choisissez une option (numéro): ");
                Console.WriteLine("1.Affichage dossier actuel");
                Console.WriteLine("2.Affichage arborescence complète");
                Console.WriteLine("3.Charger un fichier sans chiffrage");
                Console.WriteLine("4.Charger un fichier avec un chiffrage");
                Console.WriteLine("5.Enregistrer un fichier sans chiffrage");
                Console.WriteLine("6.Enregistrer un fichier avec un chiffrage");
                Console.WriteLine("7.Ajouter un dossier");
                Console.WriteLine("8.Ajouter un contact");
                Console.WriteLine("9.Changer de dossier");
                Console.WriteLine("10.Supprimer un contact dans le dossier actuel");
                Console.WriteLine("11.Supprimer un dossier dans le dossier actuel");
                Console.WriteLine("12.Sortir");
                reponse = Console.ReadLine();
                reussite = false;
                Console.ForegroundColor = ConsoleColor.White;

                switch (reponse.ToLower())
                {
                    case "1":
                        if (dossier_base != null)
                        {
                            current.afficherEnfant();
                            Console.ForegroundColor= ConsoleColor.White;
                            Console.WriteLine("\nVous êtes dans le dossier {0}", current.getNom());
                        }
                        else
                        {
                            Console.WriteLine("Il n'y a pas de dossier a afficher");
                        }
                        break;
                    case "2":
                        if (dossier_base != null)
                        {
                            dossier_base.afficher("");
                            Console.ForegroundColor = ConsoleColor.White;
                            Console.WriteLine("\nVous êtes dans le dossier {0}", current.getNom());
                        }
                        else
                        {
                            Console.WriteLine("Il n'y a pas de dossier a afficher");
                        }
                        break;
                    case "3":
                        Console.WriteLine("Quelle type de désérialisation voulez vous faire :");
                        Console.WriteLine("1.Binary");
                        Console.WriteLine("2.XMl");
                        rep = Console.ReadLine();
                        if (rep.ToLower().Equals("1"))
                        {
                            dossier_base = dataBinary.Deserialise();
                            if (dossier_base != null)
                                dossier_base.relierParent();
                        }
                        else if (rep.ToLower().Equals("2"))
                        {
                            dossier_base = dataXml.Deserialise();
                            if(dossier_base!=null)                               
                                dossier_base.relierParent();
                        }
                        else
                        {
                            Console.WriteLine("Nous n'avons pas ce type de sérialisation");
                        }
                        current = dossier_base;
                        break;
                    case "4":
                        Console.WriteLine("Quelle type de désérialisation voulez vous faire :");
                        Console.WriteLine("1.Binary");
                        Console.WriteLine("2.XMl");
                        rep = Console.ReadLine();
                        if (rep.ToLower().Equals("1"))
                        {
                            dossier_base = c.decrypterBynary();
                            if (dossier_base != null)
                                dossier_base.relierParent();
                        }
                        else if (rep.ToLower().Equals("2"))
                        {
                            dossier_base = c.decrypterXML();
                            if (dossier_base != null)
                                dossier_base.relierParent();
                        }
                        else
                        {
                            Console.WriteLine("Nous n'avons pas ce type de sérialisation");
                            dossier_base = null;
                        }

                        current = dossier_base;
                        break;
                    case "5":
                        Console.WriteLine("Quelle type de sérialisation voulez vous faire :");
                        Console.WriteLine("1.Binary");
                        Console.WriteLine("2.XMl");
                        rep = Console.ReadLine();
                        Console.WriteLine("Enregistrement du fichier en cours...");
                        if (rep.ToLower().Equals("1"))
                        {
                            if (dossier_base != null)
                                reussite = dataBinary.Serialize(dossier_base);
                        }
                        else if (rep.ToLower().Equals("2"))
                        {
                            if (dossier_base != null)
                                reussite = dataXml.Serialize(dossier_base);
                        }
                        else
                        {
                            Console.WriteLine("Nous n'avons pas ce type de sérialisation");
                        }
                        if (reussite)
                        {
                            Console.WriteLine("La sérialisation a réussi");
                        }
                        else
                        {
                            Console.WriteLine("La sérialisation a échoué");
                        }
                        break;
                    case "6":
                        Console.WriteLine("Quelle type de sérialisation voulez vous faire :");
                        Console.WriteLine("1.Binary");
                        Console.WriteLine("2.XMl");
                        rep = Console.ReadLine();
                        Console.WriteLine("Enregistrement et chiffrage du fichier en cours...");
                        if (rep.ToLower().Equals("1"))
                        {
                            if (dossier_base != null)
                                reussite = c.crypterBinary(dossier_base);
                        }
                        else if (rep.ToLower().Equals("2"))
                        {
                            if (dossier_base != null)
                                reussite = c.crypterXML(dossier_base);
                        }
                        else
                        {
                            Console.WriteLine("Nous n'avons pas ce type de sérialisation");
                        }
                        if (reussite)
                        {
                            Console.WriteLine("La sérialisation/chiffrage a réussi");
                        }
                        else
                        {
                            Console.WriteLine("La sérialisation/chiffrage a échoué");
                        }
                        break;
                    case "7":
                        nouveau = demandeCreationDossier(current);
                        if (dossier_base == null)
                        {
                            dossier_base = nouveau;
                            current = dossier_base;
                        }
                        else if (current != null)
                        {
                            current.ajouterDossier(nouveau);
                            Console.WriteLine("Ajout d'un dossier dans " + current.getNom());
                        }
                        break;
                    case "8":
                        if (current != null)
                        {
                            nouveauContact = demandeCreationContact();
                            current.ajouterContact(nouveauContact);
                        }
                        else
                        {
                            Console.WriteLine("Créez d'abord un dossier...");
                        }
                        
                        break;
                    case "9":
                        Console.WriteLine("Donnez le nom du dossier");
                        rep = Console.ReadLine();
                        if (current.changer_dossier(rep) != null)
                        {
                            current = current.changer_dossier(rep);
                            Console.WriteLine("Vous avez changé de dossier");
                        }
                        else
                        {
                            Console.WriteLine("Vous n'avez pas changé de dossier");
                        }
                        break;
                    case "10":
                        reussite = current.supprimerContact();
                        if (reussite)
                        {
                            Console.WriteLine("Le contact a été supprimé");
                        }
                        else
                        {
                            Console.WriteLine("Le contact n'a pas été supprimé");
                        }
                        break;
                    case "11":
                        reussite = current.supprimerDossier();
                        if (reussite)
                        {
                            Console.WriteLine("Le dossier a été supprimé");
                        }
                        else
                        {
                            Console.WriteLine("Le dossier n'a pas été supprimé");
                        }
                        break;
                    case "12":
                        Console.WriteLine("SortieAppli");
                        loop = false;
                        break;
                    default:
                        Console.WriteLine("Instruction inconnue");
                        break;
                }
            }
        }

    }



}
