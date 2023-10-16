using Classes;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security.Cryptography;
using System.Security.Principal;
using System.Text;
using System.Xml;

namespace Cryptage
{
    /// <summary>
    /// Cette class contient toutes les fonctions nécessaires au chiffrage et déchiffrage de fichier de sérialisation XML et Binary.
    /// </summary>
    public class CryptClass
    {
        /// <summary>
        /// Cette fonction permet de sérialiser l'arborescence dans un fichier en XML et de le chiffrer.
        /// </summary>
        /// <param name="dossier_base">Le dossier le plus haut de l'arborescence</param>
        /// <returns></returns>
        public bool crypterXML(Dossier dossier_base)
        {
            bool reussite = false;
            try
            {
                FileStream stream = new FileStream("C:\\Users\\" + Environment.UserName + "\\Documents\\saveCrypter.xml", FileMode.OpenOrCreate, FileAccess.Write);
                string mdp;
                Console.WriteLine("Donnez le mot de passe du fichier");

                mdp = MaskPassword();
                Console.WriteLine("\n");

                if (mdp.Length == 0)
                {
                    //Si l'utilisateur ne donne pas de mot de passe, on chiffre le fichier avec sa clé SID.
                    mdp = WindowsIdentity.GetCurrent().User.ToString();
                }

                //Fonction nécessaire au chiffrement du mot de passe
                byte[] key = ASCIIEncoding.UTF8.GetBytes(mdp);
                AesCryptoServiceProvider AES = new AesCryptoServiceProvider();
                AES.Key = SHA256Managed.Create().ComputeHash(key);
                AES.IV = MD5.Create().ComputeHash(key);
                stream.Write(AES.IV, 0, AES.IV.Length);

                using (CryptoStream crStream = new CryptoStream(stream, AES.CreateEncryptor(), CryptoStreamMode.Write))
                {
                    DataContractSerializer ser = new DataContractSerializer(typeof(Dossier));
                    ser.WriteObject(crStream, dossier_base);
                    crStream.Close();
                }
                stream.Close();
                reussite = true;

            }
            catch (Exception)
            {
                Console.WriteLine("Problème lors de la sérialisation/chifffrage du dossier, veuillez rééssayer");
            }
            return reussite;

        }

        /// <summary>
        /// Cette fonction permet de déchiffrer un fichier de sauvegarde XML afin de retourner le dossier le plus haut de l'arborescence.
        /// </summary>
        /// <returns>Le dossier le plus haut de l'arborescence</returns>
        public Dossier decrypterXML()
        {
            Dossier deserializedDossier = null;
            try
            {
                FileStream stream = new FileStream("C:\\Users\\" + Environment.UserName + "\\Documents\\saveCrypter.xml", FileMode.Open, FileAccess.Read);
                string mdp;
                Console.WriteLine("Donnez le mot de passe du fichier");

                mdp = MaskPassword();
                Console.WriteLine("\n");

                if (mdp.Length == 0)
                {
                    //Si l'utilisateur ne donne pas de mot de passe, le mot de passe sera le SID de l'utilisateur.
                    mdp = WindowsIdentity.GetCurrent().User.ToString();
                }

                //Fonction nécessaire au chiffrement du mot de passe
                byte[] key = ASCIIEncoding.UTF8.GetBytes(mdp);
                AesCryptoServiceProvider AES = new AesCryptoServiceProvider();
                AES.Key = SHA256Managed.Create().ComputeHash(key);
                AES.IV = MD5.Create().ComputeHash(key);
                stream.Read(AES.IV, 0, AES.IV.Length);

                using (CryptoStream crStream = new CryptoStream(stream, AES.CreateDecryptor(), CryptoStreamMode.Read))
                {
                    XmlDictionaryReader reader = XmlDictionaryReader.CreateTextReader(crStream, new XmlDictionaryReaderQuotas());
                    DataContractSerializer ser = new DataContractSerializer(typeof(Dossier));
                    deserializedDossier = (Dossier)ser.ReadObject(reader, true);
                    reader.Close();
                    crStream.Close();
                    stream.Close();
                }
            }
            catch (CryptographicException)  //Si le mot de passe n'est pas bon.
            {
                Console.WriteLine("Mot de passe faux");
            }
            catch (FileNotFoundException)   //Si il y a un soucis lors de l'ouverture du fichier.
            {
                Console.WriteLine("Problème lors de l'ouverture du fichier");
            }
            catch (Exception)       //Pour tout autre soucis.
            {
                Console.WriteLine("Problème lors de l'execution, rééssayer");
            }

            return deserializedDossier;
        }

        /// <summary>
        /// Cette fonction permet de sérialiser l'arborescence dans un fichier en Binary et de le chiffrer.
        /// </summary>
        /// <param name="dossier_base">Le dossier le plus haut de l'arborescence</param>
        /// <returns></returns>
        public bool crypterBinary(Dossier dossier_base)
        {
            bool reussite = false;
            try
            {
                BinaryFormatter bf = new BinaryFormatter();
                FileStream stream = new FileStream("C:\\Users\\" + Environment.UserName + "\\Documents\\saveCrypte.binary", FileMode.OpenOrCreate, FileAccess.Write);
                string mdp;
                Console.WriteLine("Donnez le mot de passe du fichier");

                mdp = MaskPassword();
                Console.WriteLine("\n");

                if (mdp.Length == 0)
                {
                    //Si l'utilisateur ne donne pas de mot de passe, on chiffre le fichier avec sa clé SID.
                    mdp = WindowsIdentity.GetCurrent().User.ToString();
                }
                //Fonction nécessaire au chiffrement du mot de passe
                byte[] key = ASCIIEncoding.UTF8.GetBytes(mdp);
                AesCryptoServiceProvider AES = new AesCryptoServiceProvider();
                AES.Key = SHA256Managed.Create().ComputeHash(key);
                AES.IV = MD5.Create().ComputeHash(key);
                stream.Write(AES.IV, 0, AES.IV.Length);

                CryptoStream crStream = new CryptoStream(stream, AES.CreateEncryptor(), CryptoStreamMode.Write);
                using (crStream)
                {
                    bf.Serialize(crStream, dossier_base);
                }
                crStream.Close();
                stream.Close();
                reussite = true;

            }
            catch (Exception)
            {
                Console.WriteLine("Problème lors de la sérialisation/chifffrage du dossier, veuillez rééssayer");
            }
            return reussite;
        }

        /// <summary>
        /// Cette fonction permet de déchiffrer un fichier de sauvegarde Binary afin de retourner le dossier le plus haut de l'arborescence.
        /// </summary>
        /// <returns>Le dossier le plus haut de l'arborescence</returns>
        public Dossier decrypterBynary()
        {
            Dossier rep = null;
            BinaryFormatter bf = new BinaryFormatter();
            try
            {
                FileStream stream = new FileStream("C:\\Users\\" + Environment.UserName + "\\Documents\\saveCrypte.binary", FileMode.Open, FileAccess.Read);
                string mdp;
                Console.WriteLine("Donnez le mot de passe du fichier");

                mdp = MaskPassword();
                Console.WriteLine("\n");

                if (mdp.Length == 0)
                {
                    //Si l'utilisateur ne donne pas de mot de passe, le mot de passe sera le SID de l'utilisateur.
                    mdp = WindowsIdentity.GetCurrent().User.ToString();
                }

                //Fonction nécessaire au chiffrement du mot de passe
                byte[] key = ASCIIEncoding.UTF8.GetBytes(mdp);
                AesCryptoServiceProvider AES = new AesCryptoServiceProvider();
                AES.Key = SHA256Managed.Create().ComputeHash(key);
                AES.IV = MD5.Create().ComputeHash(key);
                stream.Read(AES.IV, 0, AES.IV.Length);

                CryptoStream crStream = new CryptoStream(stream, AES.CreateDecryptor(), CryptoStreamMode.Read);

                using (crStream)
                {
                    rep = (Dossier)bf.Deserialize(crStream);

                }
            }
            catch (CryptographicException) //Si le mot de passe n'est pas bon.
            {
                Console.WriteLine("Mot de passe faux");
            }
            catch (FileNotFoundException) //Si il y a un soucis lors de l'ouverture du fichier.
            {
                Console.WriteLine("Problème lors de l'ouverture du fichier");
            }
            catch (Exception) //Pour tout autre soucis.
            {
                Console.WriteLine("Problème lors de l'execution, rééssayer");
            }

            return rep;
        }
        /// <summary>
        /// Cette fonction, récupérer sur https://social.msdn.microsoft.com/ permet de masquer le mot de passe écrit par un utilisateur.
        /// </summary>
        /// <returns>Le mot de passe non masquer</returns>
        public static string MaskPassword()
        {
            Stack<char> stack = new Stack<char>();
            ConsoleKeyInfo consoleKeyInfo;

            // push until the enter key is pressed
            while ((consoleKeyInfo = Console.ReadKey(true)).Key != ConsoleKey.Enter)
            {
                if (consoleKeyInfo.Key != ConsoleKey.Backspace)
                {
                    stack.Push(consoleKeyInfo.KeyChar);
                    Console.Write("*");
                }
                else
                {
                    Console.SetCursorPosition(Console.CursorLeft - 1, Console.CursorTop);
                    Console.Write(" ");
                    Console.SetCursorPosition(Console.CursorLeft - 1, Console.CursorTop);
                    if (stack.Count > 0) stack.Pop();
                }
            }

            return stack.Reverse().Aggregate(string.Empty, (pass, kc) => pass += kc.ToString());
        }
    }

    
}
