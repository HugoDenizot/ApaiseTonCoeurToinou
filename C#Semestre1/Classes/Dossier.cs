using System;
using System.Collections.Generic;
using System.Runtime.Serialization;

namespace Classes
{
    /// <summary>
    /// Cette class contient tout les attributs ainsi que toutes les méthodes nécessaires pour créer, modifier ou ajouter des dossiers.
    /// </summary>
    [Serializable]
    [DataContract(Name = "Customer", Namespace = "http://www.contoso.com")]
    public class Dossier
    {
        [DataMember()]
        string Nom;
        [DataMember()]
        DateTime date_de_creation;
        [DataMember()]
        DateTime date_de_modification;
        [IgnoreDataMember]
        Dossier parent;
        [DataMember()]
        List<Dossier> dossiers = new List<Dossier>();
        [DataMember()]
        List<Contact> contacts = new List<Contact>();

        /// <summary>
        /// Ceci est le constructeur d'un dossier, il est utile lors de la création d'un dossier et est le seul constructeur appelé durant
        /// le programme.
        /// </summary>
        /// <param name="nom">Le nom du dossier que l'ont veut créer.</param>
        /// <param name="parent">Le dossier(généralement actuel) qui sera le parent du futur dossier créé</param>
        public Dossier(string nom, Dossier parent)
        {
            Nom = nom;
            date_de_creation = DateTime.Now;
            date_de_modification = DateTime.Now;
            this.parent = parent;
        }

        /// <summary>
        /// Ceci est un constructeur vide de dossier, utile pour la sérialisation, il n'est pas appelé a un autre moment et ne nécessite pas
        /// d'être rempli.
        /// </summary>
        public Dossier()
        {
        }

        /// <summary>
        /// Cette fonction permet d'ajouter un contact à la liste de contact du dossier.
        /// </summary>
        /// <param name="c">Le contact que l'on veut ajouter.</param>
        
        public void ajouterContact(Contact c)
        {
            bool existe = false;
            foreach(Contact cs in contacts)
            {
                if (cs.Equals(c.getNom(), c.getPrenom(), c.getSociete()))
                {
                    existe = true;
                }
            }
            if (existe)
            {
                Console.WriteLine("Ce contact existe déjà et ne sera pas créé");
            }
            else
            {
                contacts.Add(c);
                date_de_modification = DateTime.Now;
            }
               
        }

        /// <summary>
        /// Cette fonction permet d'ajouter un dossier à la liste de dossier
        /// </summary>
        /// <param name="d">Le dossier que l'on veut ajouter</param>
        public void ajouterDossier(Dossier d)
        {
            dossiers.Add(d);
            date_de_modification = DateTime.Now;
        }

        /// <summary>
        /// Cette fonction permet d'afficher un dossier ainsi que tout les dossiers et contacts qu'il contient
        /// </summary>
        /// <param name="espace">L'espace passé en paramètre permet de donner un nombre de tabulation afin de créer une arborescence</param>
        public void afficher(string espace)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(espace +"[D]  " + Nom);
            espace += "\t";
            foreach (Contact c in contacts)
            {
                c.afficher(espace);
            }
            foreach (Dossier d in dossiers)
            {
                d.afficher(espace);
            }
        }

        /// <summary>
        /// Cette fonction permet, après désérialisation, de redonner à chaque dossier fils le parent de celui ci.
        /// </summary>
        public void relierParent()
        {
            foreach (Dossier d in dossiers)
            {
                d.parent = this;
                d.relierParent();
            }
        }

        /// <summary>
        /// Cette fonction permet de n'afficher que les dossiers enfants du dossier actuel.
        /// </summary>
        public void afficherEnfant()
        {
            Console.ForegroundColor = ConsoleColor.Red;
            foreach (Dossier d in dossiers)
            {
                Console.WriteLine("[D]  " + d.Nom);
            }
            foreach(Contact c in contacts)
            {
                c.afficher("");
            }
        }

        /// <summary>
        /// Cette fonction permet de retourner le nom du dossier
        /// </summary>
        /// <returns>Un string contenant le nom du dossier</returns>
        public string getNom()
        {
            return Nom;
        }

        /// <summary>
        /// Cette fonction permet de se balader dans l'arborescence de dossiers.
        /// </summary>
        /// <param name="nom">Le nom du dossier fils dans lequel on veut aller ou ".." si on veut revenir en arrière.</param>
        /// <returns>Retourne le nouveau dossier actuelle</returns>
        public Dossier changer_dossier(string nom)
        {
            if (nom != null)
            {
                if (nom.Equals(".."))
                {
                    return parent;
                }
                else
                {
                    foreach (Dossier d in dossiers)
                    {
                        if (d.Nom.Equals(nom))
                        {
                            return d;
                        }
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// Cette fonction permet de supprimer un contact d'un dossier.
        /// </summary>
        /// <returns>Retourne vrai si le contact est supprimé et faux sinon</returns>
        public bool supprimerContact()
        {
            string nom, prenom, societe;
            bool retour = false;
            Console.WriteLine("Donnez le nom du contact à supprimer");
            nom=Console.ReadLine();
            Console.WriteLine("Donnez le prenom du contact à supprimer");
            prenom=Console.ReadLine();
            Console.WriteLine("Donnez la société du contact à supprimer");
            societe=Console.ReadLine();
            foreach(Contact c in contacts)
            {
                if (c.Equals(nom, prenom, societe))
                {
                    contacts.Remove(c);
                    retour=true;
                }
            }
            return retour;
        }

        /// <summary>
        /// Cette fonction permet de supprimer un dossier d'un dossier.
        /// </summary>
        /// <returns>Retourne vrai si le dossier est supprimé et faux sinon</returns>
        public bool supprimerDossier()
        {
            string nom;
            bool retour = false;
            Console.WriteLine("Donnez le nom du contact à supprimer");
            nom = Console.ReadLine();
            foreach (Dossier d in dossiers)
            {
                if (d.Nom.Equals(nom))
                {
                    if (d.dossiers.Count != 0 && d.contacts.Count != 0)
                    {
                        retour = true;
                    }
                    else
                    {
                        Console.WriteLine("Le dossier n'est pas vide vous ne pouvez pas supprimé");
                    }

                }
            }
            return retour;
        }
    }
}
