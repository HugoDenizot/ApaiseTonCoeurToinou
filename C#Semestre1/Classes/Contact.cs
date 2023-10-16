using System;

namespace Classes
{
    /// <summary>
    /// La class Lien est une classe de type enum qui contient les différents liens possibles pour un contact.
    /// </summary>
    [Serializable]
    public enum Lien { ami, collegue, relation, reseau };

    /// <summary>
    /// La class contact contient tout les attributs nécessaires à un contact, ainsi que toutes les fonctions afin d'utiliser
    /// l'objet comme il faut.
    /// </summary>
    [Serializable]
    public class Contact
    {
        string Nom;
        string Prenom;
        string Courriel;
        string societe;
        Lien lien;
        DateTime date_de_creation;
        DateTime date_de_modification;

        /// <summary>
        /// Ceci est un constructeur de contact avec toutes les informations. C'est le seul constructeur qui sera utilisé dans le code.
        /// </summary>
        /// <param name="nom">Le nom du contact que l'on veut créer</param>
        /// <param name="prenom">Le prenom du contact que l'on veut créer</param>
        /// <param name="lien_choisi">Le lien du contact que l'on veut créer</param>
        /// <param name="mail">Le mail du contact que l'on veut créer</param>
        /// <param name="societe">La societe du contact que l'on veut créer</param>
        public Contact(string nom, string prenom, Lien lien_choisi, string mail, string societe)
        {
            Nom = nom;
            Prenom = prenom;
            lien = lien_choisi;
            Courriel = mail;
            this.societe = societe;
            date_de_creation = DateTime.Now;
            date_de_modification = DateTime.Now;
        }

        /// <summary>
        /// Ceci est un constructeur de contact sans paramètre. Il est nécessaire pour la sérialisation mais ne sera pas utilisé en dehors
        /// c'est donc pour cela qu'il est vide
        /// </summary>
        public Contact()
        {

        }

        /// <summary>
        /// Permet d'afficher un contact avec tout le détail sur lui.
        /// </summary>
        /// <param name="espace">L'epace passé en paramètre permet de faire une arborescence en ajoutant des tabulations a chaque dossiers</param>
        public void afficher(string espace)
        {
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine(espace +"[C]  "+ Nom + "," + Prenom + "," + Courriel + "," + societe + "," + lien);
        }

        /// <summary>
        /// Cette fonction permet de comparer deux contacts par leur nom prenom et societe
        /// </summary>
        /// <param name="n">Nom du contact</param>
        /// <param name="p">Prenom du contact</param>
        /// <param name="s">Societe du contact</param>
        /// <returns>Vrai si les contacts sont les memes et false sinon</returns>
        public bool Equals(string n, string p,string s)
        {
            if (Nom.Equals(n) && Prenom.Equals(p) && societe.Equals(s))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// Retourne le nom du contact
        /// </summary>
        /// <returns>Retourne le nom du contact</returns>
        public string getNom()
        {
            return Nom;
        }

        /// <summary>
        /// Retourne le prenom du contact
        /// </summary>
        /// <returns>Retourne le prenom du contact</returns>
        public string getPrenom()
        {
            return Prenom;
        }

        /// <summary>
        /// Retourne la societe du contact
        /// </summary>
        /// <returns>Retourne la societe du contact</returns>
        public string getSociete()
        {
            return societe;
        }

    }
}
