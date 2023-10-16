using Classes;
using System;
using System.IO;
using System.Runtime.Serialization;
using System.Xml;

namespace Serialization
{
    /// <summary>
    /// Cette class contient toutes les méthodes nécessaires à la sérialisation et désérialisation d'un fichier en type XML.
    /// </summary>
    public class XMLSerialize
    {

        /// <summary>
        /// Cette fonction permet la sérialisation en type XML de toute l'arborescence actuelle à partir du dossier de base.
        /// </summary>
        /// <param name="dossier_base">Le dossier passé en paramètre est le dossier au plus au niveau de l'arborescence</param>
        /// <returns>Cette fonction retourne un booleen vrai si la sérialisation s'est bien passé et faux si il y a eu un problème</returns>
        public bool Serialize(Dossier dossier_base)
        {
            bool reussite = false;
            try
            {
                FileStream writer = new FileStream("C:\\Users\\" + Environment.UserName + "\\Documents\\save.xml", FileMode.Create);
                DataContractSerializer ser = new DataContractSerializer(typeof(Dossier));
                ser.WriteObject(writer, dossier_base);
                writer.Close();
                reussite = true;
            }
            catch (Exception)
            {
                Console.WriteLine("Erreur lors de la sérialisation");
            }
            return reussite;
        }

        /// <summary>
        /// Cette fonction permet de déserializer une sauvegarde contenu dans un fichier de type XML
        /// </summary>
        /// <returns>Elle retourne le dossier le plus haut de l'arborence si la déserialization s'est bien
        /// passé, et un dossier null si il y a eu un soucis</returns>
        public Dossier Deserialise()
        {
            Dossier deserializedDossier = null;
            try
            {
                FileStream fs = new FileStream("C:\\Users\\" + Environment.UserName + "\\Documents\\save.xml", FileMode.Open);
                XmlDictionaryReader reader = XmlDictionaryReader.CreateTextReader(fs, new XmlDictionaryReaderQuotas());
                DataContractSerializer ser = new DataContractSerializer(typeof(Dossier));
                deserializedDossier = (Dossier)ser.ReadObject(reader, true);
                reader.Close();
                fs.Close();
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("Le fichier n'a pas été trouvé, vérifier que vous avez déjà une sauvegarde");
            }
            catch (Exception)
            {
                Console.WriteLine("Erreur imprévue");
            }
            return deserializedDossier;
        }
    }
}
