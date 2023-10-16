# Projet C# Semestre 1

# Explication Projet

Le but du projet était de créer une application console en C#, représentant une gestion de contact. Cette application
permettait donc de créer des dossiers, pour y ajouter d'autres dossiers ou des contacts dedans, et ensuite, le but est
de pouvoir enregistrer ou recharger le fichier grâce à la **sérialisation** et de protéger ces fichiers par **chiffrage**

# Les 3 grands projets

## Les classes Dossiers et Contact

Pour commencer il faut donc faire 2 classes Dossier et Contact qui contiennent chacuns différents attributs.

### La classe Dossier

La classe Dossier est constitué de 6 attributs :
	-Un nom
	-Une date de création
	-Une date de modification
	-Un dossier parent (celui dans lequel il est)
	-Une liste de dossiers
	-Une liste de contacts

Certains de ces attributs ne sont pas utilisés plus tard dans le code (comme les dates, elles sont instanciés et modifiés à l'ajout d'un contact
mais je ne les affiche pas car je ne vois pas d'utilité).

### La classe Contact
La classe Contact est constitué de 7 attributs :
	-Un nom
	-Un prénom
	-Un Courriel
	-Une société
	-Un lien (entre ami, collegue, relation et reseau)
	-Une date de création
	-Une date de modification

Idem que pour les dossiers les dates ne sont jamais utilisés (voir jamais modifié car je ne voyais pas quand le modifié car on ne peut pas modifier un contact).
Le courriel est vérifié lors de la création d'un Contact de sorte à ce que ça soit une adresse mail valide sur son format.

## La sérialisation
La sérialisation peut etre fait en 2 types:

### Binary
Cette sérialisation va créé un fichier qui s'appelle save.binary grâce à la class BinaryFormatter.

### XML
Cette sérialisation va créé un fichier qui s'appelle save.xml grâce à la class DataContractSerializer.

Ces deux classes vont permettre de sérialiser(sauvegarder) les données afin de pouvoir les recharger plus tard. Lors de la recharge on appellera aussi la fonction relierParent
qui permettra de donner à chaque dossier le bon dossier dans l'attribut parent.
Les fichiers seront sauvegardé dans le dossier Documents de l'utilisateur.

## Le chiffrement

Le chiffrement se fait grâce à la classe CryptoStream et permet de créer un fichier avec un mot de passe choisi par l'utilisateur lors de sa création, ou si il ne choisit rien
son SID.
Lors du saisie du mot de passe on utilisera la méthode MaskPassword() récupérer sur le site https://social.msdn.microsoft.com/Forums/fr-FR/55e423d6-7917-4e7d-822d-ce1adcd547c6/comment-masquer-les-caractres-de-mot-de-passe-dans-la-console-lors-de-la-saisie-?forum=visualcsharpfr afin de protéger le mot de passe.
Les fichiers seront sauvegardé dans le dossier Documents de l'utilisateur et s'appelleront saveCrypter.xml ou saveCrypte.binary .

# Les moments difficiles du projet

Le moment difficile était la sérialisation XML car je n'ai pas réussi à utiliser la class XMLSerializer.
Je n'ai pas fait certains plus demandés dans la partie sérialisation car le mot de passe est déjà fait dans la partie chiffrement et je ne voyais pas pourquoi renommé le fichier
par le SID de l'utilisateur.