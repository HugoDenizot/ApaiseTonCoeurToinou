using Classes;
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Serialization
{
    /// <summary>
    /// Cette class contient les méthodes nécessaires à la sérialization en type Binary.
    /// </summary>
    public class BinarySerialize
    {
        /// <summary>
        /// Cette fonction permet la sérialisation en type binary de toute l'arborescence actuelle à partir du dossier de base.
        /// </summary>
        /// <param name="dossier_base">Le dossier passé en paramètre est le dossier au plus au niveau de l'arborescence</param>
        /// <returns>Cette fonction retourne un booleen vrai si la sérialisation s'est bien passé et faux si il y a eu un problème</returns>
        public bool Serialize(Dossier dossier_base)
        {
            BinaryFormatter bf = new BinaryFormatter();
            bool reussite = false;
            string chemin = "C:\\Users\\" + Environment.UserName + "\\Documents\\save.binary";
            try
            {
                FileStream fsout = new FileStream(chemin, FileMode.Create, FileAccess.Write, FileShare.None);
                using (fsout)
                {
                    bf.Serialize(fsout, dossier_base);
                    reussite = true;
                }
            }
            catch (Exception)
            {
                Console.WriteLine("Erreur lors de la sérialisation");
            }
            return reussite;
        }

        /// <summary>
        /// Cette fonction permet de déserializer une sauvegarde contenu dans un fichier de type Binary
        /// </summary>
        /// <returns>Elle retourne le dossier le plus haut de l'arborence si la déserialization s'est bien
        /// passé, et un dossier null si il y a eu un soucis</returns>
        public Dossier Deserialise()
        {
            Dossier rep = null;
            BinaryFormatter bf = new BinaryFormatter();
            string chemin = "C:\\Users\\" + Environment.UserName + "\\Documents\\save.binary";

            try
            {
                FileStream fs = new FileStream(chemin, FileMode.Open, FileAccess.Read, FileShare.None);

                using (fs)
                {
                    rep = (Dossier)bf.Deserialize(fs);

                }
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("Le fichier n'a pas été trouvé, vérifier que vous avez déjà une sauvegarde");
            }
            catch (Exception)
            {
                Console.WriteLine("Erreur imprévue");
            }

            return rep;

        }
    }
}
