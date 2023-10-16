[![pipeline status](https://gitlab.isima.fr/it-forge/2022/tp3-ballejos-denizot/badges/master/pipeline.svg)](https://gitlab.isima.fr/it-forge/2022/tp3-ballejos-denizot/-/commits/master)
[![coverage report](https://gitlab.isima.fr/it-forge/2022/tp3-ballejos-denizot/badges/master/coverage.svg)](https://gitlab.isima.fr/it-forge/2022/tp3-ballejos-denizot/-/commits/master)
[![Latest Release](https://gitlab.isima.fr/it-forge/2022/tp3-ballejos-denizot/-/badges/release.svg)](https://gitlab.isima.fr/it-forge/2022/tp3-ballejos-denizot/-/releases)

# Infos étudiant :

Par binôme Nom Prénom:
 * BALLEJOS Lilian
 * DENIZOT Hugo 

# TP 3

Le but de ce TP est de mettre en place un processus d'intégration continue en se basant sur le projet précédent.

## 1 Création d'un espace projet dédié sous gitlab
1. Pour mettre en place une chaine d'intégration continue initialisez un nouveau projet sous [GitLab](https://gitlab.isima.fr).
1. Ajouter dans la liste des développeurs votre binôme. (Settings/Members)
1. Ajouter en reporter `tjouve` & `iia_samorel`.
1. Ajoutez ce compte rendu comme readme de votre projet.
    * Vous pouvez le faire directement depuis l'interface avec *new File*
    * Copier le code markdown, il est possible d'editer le document via l'interface web directement sur gitlab
    * **Renseignez vos noms en haut du compte rendu**
1. Ajoutez une licence pour indiquer sous quels termes votre production est disponible
    * Cliquez sur **Add License**, il est possible de rédiger soi-même le contenu, ou de selectionner une licence existante (Apache, MIT, GNU ...). Le site [choose a license](https://choosealicense.com/licenses/) propose un comparatif entre les différentes liences les plus courantes.


## 2 Initialisation du projet
Pour prendre en charge la gestion des dépendances et l'automatisation de la construction de l'application nous utiliserons `Maven`.
Pour démarrer rapidement le projet nous allons faire du *scaffolding*. Pour ce faire nous utiliserons [Spring Boot](https://projects.spring.io/spring-boot/). Et plus particuliérement [Spring initializr](https://start.spring.io/). 

### 2.1 Spring Initializer (Optionel)
1. Créer un squelette d'application avec [Spring initializr](https://start.spring.io/) :
    1. choisissez comme groupe id **isima.F2**
    2. comme nom d'artefact vous saisirez **TP3.`nom binome`** 
    3. téléchargez ce template de projet.
1. clonez votre nouveau projet localement
    1. dézippez l'archive dans votre repo local, ce dernier ne devrait contenir que l'arborescence des sources, le pom et votre readme
    1. commitez et pushez sur le serveur


### 2.2 Utilisation de maven
Avant de reporter le code du TP2 nous allons nous familiariser avec *Maven*

#### 2.2.1 Convention over configuration
Pour permettre de développer plus rapidement des applications une bonne pratique est de respecter certaines normes.

Dans notre cas en utilisant **Spring Initializer** nous avons rapidement généré un squelette d'application utilisant maven et fournissant un certain nombre de fonctionnalitées transverses.
Notamment un framework de test **JUnit** et un framework de logging **Logback**


* A quoi correspondent les fichiers présents dans le zip ? 
    * pom.xml
    * .gitignore
    * décrire l'arborescence de répertoire
            
* Nos réponses:
    * Ce fichier XML est le descripteur du projet et contient toutes les informations nécessaires à Maven pour gérer le cycle de vie du projet
    * Fichier contenant tout les fichiers qui seront ignorer lors d'un commit sur le repertoire distant car inutile pour le projet ou trop lourd (.vscode par exemple)
    * src : contient tous les codes sources du projet (dans le dossier test il y a nos bibliothèques de test et dans main notre main) | A l'origine du dossier il y a tous les fichier nécessaire au bon fonctionnement de Maven.

#### 2.2.2 Gestion des dépendances 

Dans le nouveau projet on retrouve une classe *Application.java* sous *src/main/java* dans le package *isima.F2.TP3.`nom binome`*
* Dans cette classe créez un logger et loggez un `Hello Word` en *warning*

```java
private static final Logger logger = LoggerFactory.getLogger(DemoApplication.class);

public static void main(String[] args) {
    SpringApplication.run(DemoApplication.class, args);
    logger.warn("Hello Word");

}
```

* Exécutez votre programme

```bash
  .   ____          _            __ _ _
 /\\ / ___'_ __ _ _(_)_ __  __ _ \ \ \ \
( ( )\___ | '_ | '_| | '_ \/ _` | \ \ \ \
 \\/  ___)| |_)| | | | | || (_| |  ) ) ) )
  '  |____| .__|_| |_|_| |_\__, | / / / /
 =========|_|==============|___/=/_/_/_/
 :: Spring Boot ::                (v2.7.5)

2022-10-25 11:54:49.019  INFO 22950 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Starting Application using Java 17.0.1 on a212pc12L.local.isima.fr with PID 22950 (/mnt/local.isima.fr/liballejos/ZZ2/Forge/TP3-forge-ZZ2/target/classes started by liballejos in /mnt/local.isima.fr/liballejos/ZZ2/Forge/TP3-forge-ZZ2)
2022-10-25 11:54:49.021  INFO 22950 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : No active profile set, falling back to 1 default profile: "default"
2022-10-25 11:54:49.425  INFO 22950 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Started Application in 0.792 seconds (JVM running for 1.128)
2022-10-25 11:54:49.428  WARN 22950 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Hello Word

Process finished with exit code 0
```

Vous remarquerez qu'il n'est pas nécessaire d'ajouter la dépendance vers un logger (ici *logback*). C'est une dépendance classique d'un projet java. Elle est déjà présente dans le pom de *spring boot*.

Pour illustrer la gestion des dépendances automatiques vous ajouterez une dépendance vers la librairie **commons-lang3** de **apache**
* Ajout de la dépendance *Apache commons lang3*
    * Pour ce faire recherche `commons-lang3` sur [MVNrepository](https://mvnrepository.com).
    * selectionnez la derniére version
    * copiez la déclaration et collez là dans votre *pom.xml*
    * Décrivrez rapidement le fonctionnement de la résolution de dépendance
 
On remarque qu'en rajoutant dans le **pom.xml** qui gère les dépendances la référence d'une nouvelle dépendance, celle -ci est automatiquement téléchargée par maeven
lorsqu'on refresh celui-ci. Meaven cherche donc le repertoire de la dépendance et l'ajoute dans les dépendances nécessaires de notre projet. Il ajoute la dépendance voulue ainsi que toutes celles dont a besoin la nouvelle dépendance.

* Utilisez la classe utilitaire `StringUtils` et sa méthode `reverse` pour afficher dans la log au niveau *debug* vos noms à la suite du Hello Word.
    * La ligne de log n'apparait pas dans la console car le niveau de trace par defaut est `WARN`.
    * [Spring boot logging](https://docs.spring.io/spring-boot/docs/current/reference/html/howto-logging.html) indique comment changer le niveau de trace. (Il n'est pas nécessaire d'ajouter la dépendance elle est déjà présente).
    * Un fois le niveau de trace par defaut changé vous devriez voir le résultat de votre commande.
    * Quel fichier de configuration est modifié ? 

```  .   ____          _            __ _ _
 /\\ / ___'_ __ _ _(_)_ __  __ _ \ \ \ \
( ( )\___ | '_ | '_| | '_ \/ _` | \ \ \ \
 \\/  ___)| |_)| | | | | || (_| |  ) ) ) )
  '  |____| .__|_| |_|_| |_\__, | / / / /
 =========|_|==============|___/=/_/_/_/
 :: Spring Boot ::                (v2.7.5)

2022-11-15 10:24:06.732  INFO 5115 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Starting Application using Java 17.0.1 on a212pc01L.local.isima.fr with PID 5115 (/mnt/local.isima.fr/liballejos/ZZ2/Forge/tp3-ballejos-denizot/target/classes started by liballejos in /mnt/local.isima.fr/liballejos/ZZ2/Forge/tp3-ballejos-denizot)
2022-11-15 10:24:06.734 DEBUG 5115 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Running with Spring Boot v2.7.5, Spring v5.3.23
2022-11-15 10:24:06.735  INFO 5115 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : No active profile set, falling back to 1 default profile: "default"
2022-11-15 10:24:07.104  INFO 5115 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Started Application in 0.73 seconds (JVM running for 1.029)
2022-11-15 10:24:07.107  WARN 5115 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Hello Word
2022-11-15 10:24:07.111 DEBUG 5115 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.Application     : Reverse en Debug: TOZINED SOJELLAB

Process finished with exit code 0
```

Notre message en **Debug** apparait bien et nous arrivons à utiliser la méthode **reverse()** preuve que maeven a bien géré les dépendances !

Nous avons modifié le fichier **application.properties** situé dans le dossier **ressources**

En ajoutant la ligne `logging.level.isima=debug` on change la couche de débogage de notre logger à la couche **debug** pour tout notre packet **isima**

#### 2.2.3 Gestion du cycle de vie

Dans cette partie nous allons utiliser les commandes de build de manven. Ces commandes permettentent d'automatiser certaines taches.
[Maven Lyfe Cycle](https://maven.apache.org/guides/introduction/introduction-to-the-lifecycle.html) décrit l'ensemble des instructions et l'enchainement des différentes phases de **Maven**.

L'archive générée via spring initializer contient un répertoire `.mvn` et 2 scripts `mvnw` et `mvnw.bat`. Le projet contient par defaut un *wrapper* qui permet d'avoir une installation locale de maven pour ne pas être dépendant du systéme sur lequel on développe.

Il est possible de lancer directement des taches maven en appellant le script (`mvnw` pour *linux* et `mvnw.bat` pour *windows* ). 

Par example `./mvnw.bat clean` permet de supprimer les classes compilées dans le repertoire target.

En utilisant la ligne de commande nous allons compiler, tester et packager l'application sous la forme d'un jar.

##### 2.2.3.1 Compilation
* Quelle est la commande à lancer pour compiler l'application ?
* Quelle est la commande à lancer pour compiler & éxécuter les tests ?
* Quel sont les fichiers / répertoires générés par cette commande ?

**Nos réponses:**

* Pour compiler: `mvn compile`
* Pour compiler et executer les test: `mvn test` (le programme compile si besoin puis effectue les tests)
* Le repertoire **target** est généré à la première compilation puis son contenu est modifié à chaque compilation selon nos fichiers .java modifié
    
##### 2.2.3.2 Packaging
* Quelle est la commande à lancer ?
* Quel sont les fichiers / répertoires générés par cette commande ?

**Nos réponses:**

* `mvn package` prend notre code compilé puis crée un package distribuable à partir de celui-ci (.jar).
* Les fichiers générés sont dans le repertoire **target** sous le nom **nom-du-projet-VERSION-.jar** et **nom-du-projet-VERSION-.jar.original**.

La différence entre .jar.original et .jar est que le .jar est un **fatjar**. C'est à dire qu'il possède tout ce qu'il faut en lui afin d'éxecuter le programme avec un "simple double click".

A l'inverse, le .jar contient seulement le code et les références vers les dépendances.
      
    
### 2.3 Reportez le code du TP2           
* Reportez vos classes d'implémentation et de test dans le nouveau projet
    * Votre implémentation dans le repertoire src/main/java/*pakcage_name*/*Application
    * Votre classe de test dans le repertoire src/test/java/*pakcage_name*/*ApplicationTests
* Effectuez le packaging de votre application pour lancer la compilation et les tests.
 
```[INFO] Scanning for projects...
[INFO] 
[INFO] -------------------< isima.F2:TP3.BALLEJOS-DENIZOT >--------------------
[INFO] Building TP3.BALLEJOS-DENIZOT 0.0.1-SNAPSHOT
[INFO] --------------------------------[ jar ]---------------------------------
[INFO] 
[INFO] --- maven-resources-plugin:3.2.0:resources (default-resources) @ TP3.BALLEJOS-DENIZOT ---
[INFO] Using 'UTF-8' encoding to copy filtered resources.
[INFO] Using 'UTF-8' encoding to copy filtered properties files.
[INFO] Copying 1 resource
[INFO] Copying 0 resource
[INFO] 
[INFO] --- maven-compiler-plugin:3.10.1:compile (default-compile) @ TP3.BALLEJOS-DENIZOT ---
[INFO] Nothing to compile - all classes are up to date
[INFO] 
[INFO] --- maven-resources-plugin:3.2.0:testResources (default-testResources) @ TP3.BALLEJOS-DENIZOT ---
[INFO] Using 'UTF-8' encoding to copy filtered resources.
[INFO] Using 'UTF-8' encoding to copy filtered properties files.
[INFO] skip non existing resourceDirectory /mnt/local.isima.fr/liballejos/ZZ2/Forge/tp3-ballejos-denizot/src/test/resources
[INFO] 
[INFO] --- maven-compiler-plugin:3.10.1:testCompile (default-testCompile) @ TP3.BALLEJOS-DENIZOT ---
[INFO] Nothing to compile - all classes are up to date
[INFO] 
[INFO] --- maven-surefire-plugin:2.22.2:test (default-test) @ TP3.BALLEJOS-DENIZOT ---
[INFO] 
[INFO] -------------------------------------------------------
[INFO]  T E S T S
[INFO] -------------------------------------------------------
[INFO] Running isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite
11:27:00.489 [main] DEBUG org.springframework.test.context.BootstrapUtils - Instantiating CacheAwareContextLoaderDelegate from class [org.springframework.test.context.cache.DefaultCacheAwareContextLoaderDelegate]
11:27:00.504 [main] DEBUG org.springframework.test.context.BootstrapUtils - Instantiating BootstrapContext using constructor [public org.springframework.test.context.support.DefaultBootstrapContext(java.lang.Class,org.springframework.test.context.CacheAwareContextLoaderDelegate)]
11:27:00.535 [main] DEBUG org.springframework.test.context.BootstrapUtils - Instantiating TestContextBootstrapper for test class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite] from class [org.springframework.boot.test.context.SpringBootTestContextBootstrapper]
11:27:00.542 [main] INFO org.springframework.boot.test.context.SpringBootTestContextBootstrapper - Neither @ContextConfiguration nor @ContextHierarchy found for test class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite], using SpringBootContextLoader
11:27:00.545 [main] DEBUG org.springframework.test.context.support.AbstractContextLoader - Did not detect default resource location for test class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite]: class path resource [isima/F2/TP3/BALLEJOSDENIZOT/TestIndemnite-context.xml] does not exist
11:27:00.545 [main] DEBUG org.springframework.test.context.support.AbstractContextLoader - Did not detect default resource location for test class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite]: class path resource [isima/F2/TP3/BALLEJOSDENIZOT/TestIndemniteContext.groovy] does not exist
11:27:00.545 [main] INFO org.springframework.test.context.support.AbstractContextLoader - Could not detect default resource locations for test class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite]: no resource found for suffixes {-context.xml, Context.groovy}.
11:27:00.546 [main] INFO org.springframework.test.context.support.AnnotationConfigContextLoaderUtils - Could not detect default configuration classes for test class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite]: TestIndemnite does not declare any static, non-private, non-final, nested classes annotated with @Configuration.
11:27:00.578 [main] DEBUG org.springframework.test.context.support.ActiveProfilesUtils - Could not find an 'annotation declaring class' for annotation type [org.springframework.test.context.ActiveProfiles] and class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite]
11:27:00.627 [main] DEBUG org.springframework.context.annotation.ClassPathScanningCandidateComponentProvider - Identified candidate component class: file [/mnt/local.isima.fr/liballejos/ZZ2/Forge/tp3-ballejos-denizot/target/classes/isima/F2/TP3/BALLEJOSDENIZOT/Application.class]
11:27:00.632 [main] INFO org.springframework.boot.test.context.SpringBootTestContextBootstrapper - Found @SpringBootConfiguration isima.F2.TP3.BALLEJOSDENIZOT.Application for test class isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite
11:27:00.692 [main] DEBUG org.springframework.boot.test.context.SpringBootTestContextBootstrapper - @TestExecutionListeners is not present for class [isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite]: using defaults.
11:27:00.692 [main] INFO org.springframework.boot.test.context.SpringBootTestContextBootstrapper - Loaded default TestExecutionListener class names from location [META-INF/spring.factories]: [org.springframework.boot.test.mock.mockito.MockitoTestExecutionListener, org.springframework.boot.test.mock.mockito.ResetMocksTestExecutionListener, org.springframework.boot.test.autoconfigure.restdocs.RestDocsTestExecutionListener, org.springframework.boot.test.autoconfigure.web.client.MockRestServiceServerResetTestExecutionListener, org.springframework.boot.test.autoconfigure.web.servlet.MockMvcPrintOnlyOnFailureTestExecutionListener, org.springframework.boot.test.autoconfigure.web.servlet.WebDriverTestExecutionListener, org.springframework.boot.test.autoconfigure.webservices.client.MockWebServiceServerTestExecutionListener, org.springframework.test.context.web.ServletTestExecutionListener, org.springframework.test.context.support.DirtiesContextBeforeModesTestExecutionListener, org.springframework.test.context.event.ApplicationEventsTestExecutionListener, org.springframework.test.context.support.DependencyInjectionTestExecutionListener, org.springframework.test.context.support.DirtiesContextTestExecutionListener, org.springframework.test.context.transaction.TransactionalTestExecutionListener, org.springframework.test.context.jdbc.SqlScriptsTestExecutionListener, org.springframework.test.context.event.EventPublishingTestExecutionListener]
11:27:00.699 [main] DEBUG org.springframework.boot.test.context.SpringBootTestContextBootstrapper - Skipping candidate TestExecutionListener [org.springframework.test.context.web.ServletTestExecutionListener] due to a missing dependency. Specify custom listener classes or make the default listener classes and their required dependencies available. Offending class: [javax/servlet/ServletContext]
11:27:00.701 [main] DEBUG org.springframework.boot.test.context.SpringBootTestContextBootstrapper - Skipping candidate TestExecutionListener [org.springframework.test.context.transaction.TransactionalTestExecutionListener] due to a missing dependency. Specify custom listener classes or make the default listener classes and their required dependencies available. Offending class: [org/springframework/transaction/interceptor/TransactionAttributeSource]
11:27:00.701 [main] DEBUG org.springframework.boot.test.context.SpringBootTestContextBootstrapper - Skipping candidate TestExecutionListener [org.springframework.test.context.jdbc.SqlScriptsTestExecutionListener] due to a missing dependency. Specify custom listener classes or make the default listener classes and their required dependencies available. Offending class: [org/springframework/transaction/interceptor/TransactionAttribute]
11:27:00.701 [main] INFO org.springframework.boot.test.context.SpringBootTestContextBootstrapper - Using TestExecutionListeners: [org.springframework.test.context.support.DirtiesContextBeforeModesTestExecutionListener@f627d13, org.springframework.test.context.event.ApplicationEventsTestExecutionListener@4e928fbf, org.springframework.boot.test.mock.mockito.MockitoTestExecutionListener@352ff4da, org.springframework.boot.test.autoconfigure.SpringBootDependencyInjectionTestExecutionListener@3224a577, org.springframework.test.context.support.DirtiesContextTestExecutionListener@2e32ccc5, org.springframework.test.context.event.EventPublishingTestExecutionListener@748741cb, org.springframework.boot.test.mock.mockito.ResetMocksTestExecutionListener@3e44f2a5, org.springframework.boot.test.autoconfigure.restdocs.RestDocsTestExecutionListener@295cf707, org.springframework.boot.test.autoconfigure.web.client.MockRestServiceServerResetTestExecutionListener@1130520d, org.springframework.boot.test.autoconfigure.web.servlet.MockMvcPrintOnlyOnFailureTestExecutionListener@5f77d0f9, org.springframework.boot.test.autoconfigure.web.servlet.WebDriverTestExecutionListener@463fd068, org.springframework.boot.test.autoconfigure.webservices.client.MockWebServiceServerTestExecutionListener@895e367]
11:27:00.703 [main] DEBUG org.springframework.test.context.support.AbstractDirtiesContextTestExecutionListener - Before test class: context [DefaultTestContext@11d8ae8b testClass = TestIndemnite, testInstance = [null], testMethod = [null], testException = [null], mergedContextConfiguration = [MergedContextConfiguration@479cbee5 testClass = TestIndemnite, locations = '{}', classes = '{class isima.F2.TP3.BALLEJOSDENIZOT.Application}', contextInitializerClasses = '[]', activeProfiles = '{}', propertySourceLocations = '{}', propertySourceProperties = '{org.springframework.boot.test.context.SpringBootTestContextBootstrapper=true}', contextCustomizers = set[org.springframework.boot.test.context.filter.ExcludeFilterContextCustomizer@5fbe4146, org.springframework.boot.test.json.DuplicateJsonObjectContextCustomizerFactory$DuplicateJsonObjectContextCustomizer@71e9ddb4, org.springframework.boot.test.mock.mockito.MockitoContextCustomizer@0, org.springframework.boot.test.web.client.TestRestTemplateContextCustomizer@5c671d7f, org.springframework.boot.test.autoconfigure.actuate.metrics.MetricsExportContextCustomizerFactory$DisableMetricExportContextCustomizer@38102d01, org.springframework.boot.test.autoconfigure.properties.PropertyMappingContextCustomizer@0, org.springframework.boot.test.autoconfigure.web.servlet.WebDriverContextCustomizerFactory$Customizer@610f7aa, org.springframework.boot.test.context.SpringBootTestArgs@1, org.springframework.boot.test.context.SpringBootTestWebEnvironment@3abbfa04], contextLoader = 'org.springframework.boot.test.context.SpringBootContextLoader', parent = [null]], attributes = map[[empty]]], class annotated with @DirtiesContext [false] with mode [null].
11:27:00.712 [main] DEBUG org.springframework.test.context.support.DependencyInjectionTestExecutionListener - Performing dependency injection for test context [[DefaultTestContext@11d8ae8b testClass = TestIndemnite, testInstance = isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite@34f6515b, testMethod = [null], testException = [null], mergedContextConfiguration = [MergedContextConfiguration@479cbee5 testClass = TestIndemnite, locations = '{}', classes = '{class isima.F2.TP3.BALLEJOSDENIZOT.Application}', contextInitializerClasses = '[]', activeProfiles = '{}', propertySourceLocations = '{}', propertySourceProperties = '{org.springframework.boot.test.context.SpringBootTestContextBootstrapper=true}', contextCustomizers = set[org.springframework.boot.test.context.filter.ExcludeFilterContextCustomizer@5fbe4146, org.springframework.boot.test.json.DuplicateJsonObjectContextCustomizerFactory$DuplicateJsonObjectContextCustomizer@71e9ddb4, org.springframework.boot.test.mock.mockito.MockitoContextCustomizer@0, org.springframework.boot.test.web.client.TestRestTemplateContextCustomizer@5c671d7f, org.springframework.boot.test.autoconfigure.actuate.metrics.MetricsExportContextCustomizerFactory$DisableMetricExportContextCustomizer@38102d01, org.springframework.boot.test.autoconfigure.properties.PropertyMappingContextCustomizer@0, org.springframework.boot.test.autoconfigure.web.servlet.WebDriverContextCustomizerFactory$Customizer@610f7aa, org.springframework.boot.test.context.SpringBootTestArgs@1, org.springframework.boot.test.context.SpringBootTestWebEnvironment@3abbfa04], contextLoader = 'org.springframework.boot.test.context.SpringBootContextLoader', parent = [null]], attributes = map['org.springframework.test.context.event.ApplicationEventsTestExecutionListener.recordApplicationEvents' -> false]]].

  .   ____          _            __ _ _
 /\\ / ___'_ __ _ _(_)_ __  __ _ \ \ \ \
( ( )\___ | '_ | '_| | '_ \/ _` | \ \ \ \
 \\/  ___)| |_)| | | | | || (_| |  ) ) ) )
  '  |____| .__|_| |_|_| |_\__, | / / / /
 =========|_|==============|___/=/_/_/_/
 :: Spring Boot ::                (v2.7.5)

2022-11-15 11:27:00.934  INFO 9875 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.TestIndemnite   : Starting TestIndemnite using Java 17.0.1 on a212pc01L.local.isima.fr with PID 9875 (started by liballejos in /mnt/local.isima.fr/liballejos/ZZ2/Forge/tp3-ballejos-denizot)
2022-11-15 11:27:00.935 DEBUG 9875 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.TestIndemnite   : Running with Spring Boot v2.7.5, Spring v5.3.23
2022-11-15 11:27:00.936  INFO 9875 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.TestIndemnite   : No active profile set, falling back to 1 default profile: "default"
2022-11-15 11:27:01.321  INFO 9875 --- [           main] i.F2.TP3.BALLEJOSDENIZOT.TestIndemnite   : Started TestIndemnite in 0.593 seconds (JVM running for 1.216)
[INFO] Tests run: 3, Failures: 0, Errors: 0, Skipped: 0, Time elapsed: 1.198 s - in isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite
[INFO] Running isima.F2.TP3.BALLEJOSDENIZOT.ApplicationTests
2022-11-15 11:27:01.634  INFO 9875 --- [           main] .b.t.c.SpringBootTestContextBootstrapper : Neither @ContextConfiguration nor @ContextHierarchy found for test class [isima.F2.TP3.BALLEJOSDENIZOT.ApplicationTests], using SpringBootContextLoader
2022-11-15 11:27:01.635  INFO 9875 --- [           main] o.s.t.c.support.AbstractContextLoader    : Could not detect default resource locations for test class [isima.F2.TP3.BALLEJOSDENIZOT.ApplicationTests]: no resource found for suffixes {-context.xml, Context.groovy}.
2022-11-15 11:27:01.635  INFO 9875 --- [           main] t.c.s.AnnotationConfigContextLoaderUtils : Could not detect default configuration classes for test class [isima.F2.TP3.BALLEJOSDENIZOT.ApplicationTests]: ApplicationTests does not declare any static, non-private, non-final, nested classes annotated with @Configuration.
2022-11-15 11:27:01.637  INFO 9875 --- [           main] .b.t.c.SpringBootTestContextBootstrapper : Found @SpringBootConfiguration isima.F2.TP3.BALLEJOSDENIZOT.Application for test class isima.F2.TP3.BALLEJOSDENIZOT.ApplicationTests
2022-11-15 11:27:01.638  INFO 9875 --- [           main] .b.t.c.SpringBootTestContextBootstrapper : Loaded default TestExecutionListener class names from location [META-INF/spring.factories]: [org.springframework.boot.test.mock.mockito.MockitoTestExecutionListener, org.springframework.boot.test.mock.mockito.ResetMocksTestExecutionListener, org.springframework.boot.test.autoconfigure.restdocs.RestDocsTestExecutionListener, org.springframework.boot.test.autoconfigure.web.client.MockRestServiceServerResetTestExecutionListener, org.springframework.boot.test.autoconfigure.web.servlet.MockMvcPrintOnlyOnFailureTestExecutionListener, org.springframework.boot.test.autoconfigure.web.servlet.WebDriverTestExecutionListener, org.springframework.boot.test.autoconfigure.webservices.client.MockWebServiceServerTestExecutionListener, org.springframework.test.context.web.ServletTestExecutionListener, org.springframework.test.context.support.DirtiesContextBeforeModesTestExecutionListener, org.springframework.test.context.event.ApplicationEventsTestExecutionListener, org.springframework.test.context.support.DependencyInjectionTestExecutionListener, org.springframework.test.context.support.DirtiesContextTestExecutionListener, org.springframework.test.context.transaction.TransactionalTestExecutionListener, org.springframework.test.context.jdbc.SqlScriptsTestExecutionListener, org.springframework.test.context.event.EventPublishingTestExecutionListener]
2022-11-15 11:27:01.639  INFO 9875 --- [           main] .b.t.c.SpringBootTestContextBootstrapper : Using TestExecutionListeners: [org.springframework.test.context.support.DirtiesContextBeforeModesTestExecutionListener@c3edf4c, org.springframework.test.context.event.ApplicationEventsTestExecutionListener@5af8bb51, org.springframework.boot.test.mock.mockito.MockitoTestExecutionListener@799ed4e8, org.springframework.boot.test.autoconfigure.SpringBootDependencyInjectionTestExecutionListener@2e66bc32, org.springframework.test.context.support.DirtiesContextTestExecutionListener@54d8c20d, org.springframework.test.context.event.EventPublishingTestExecutionListener@4b65d9f4, org.springframework.boot.test.mock.mockito.ResetMocksTestExecutionListener@44536de4, org.springframework.boot.test.autoconfigure.restdocs.RestDocsTestExecutionListener@5fcfde70, org.springframework.boot.test.autoconfigure.web.client.MockRestServiceServerResetTestExecutionListener@4d95a72e, org.springframework.boot.test.autoconfigure.web.servlet.MockMvcPrintOnlyOnFailureTestExecutionListener@28da7d11, org.springframework.boot.test.autoconfigure.web.servlet.WebDriverTestExecutionListener@77b919a3, org.springframework.boot.test.autoconfigure.webservices.client.MockWebServiceServerTestExecutionListener@5624657a]
[INFO] Tests run: 1, Failures: 0, Errors: 0, Skipped: 0, Time elapsed: 0.001 s - in isima.F2.TP3.BALLEJOSDENIZOT.ApplicationTests
[INFO] 
[INFO] Results:
[INFO] 
[INFO] Tests run: 4, Failures: 0, Errors: 0, Skipped: 0
[INFO] 
[INFO] 
[INFO] --- maven-jar-plugin:3.2.2:jar (default-jar) @ TP3.BALLEJOS-DENIZOT ---
[INFO] 
[INFO] --- spring-boot-maven-plugin:2.7.5:repackage (repackage) @ TP3.BALLEJOS-DENIZOT ---
[INFO] Replacing main artifact with repackaged archive
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------
[INFO] Total time:  3.150 s
[INFO] Finished at: 2022-11-15T11:27:02+01:00
[INFO] ------------------------------------------------------------------------
```

**Notre Analyse:**

On remarque que nos tests du TP2 ont bien été pris en compte lors de l'utilisation de la commande `mvn package` !
En effet, il effectue deux batteries de Test :

* Le test de base qui se situe dans **ApplicationsTests.java**
* Les 3 tests que l'on avait créés dans **TestIndemnite.java**

Il confirme bien localement dans chacuns des tests que ceux-ci sont validés (`[INFO] Tests run: 3, Failures: 0, Errors: 0, Skipped: 0, Time elapsed: 1.198 s - in isima.F2.TP3.BALLEJOSDENIZOT.TestIndemnite` pour nos tests personnels par exemple)

Puis il confirme globalement que tous les tests sont passés:

```
[INFO] Results:
[INFO] 
[INFO] Tests run: 4, Failures: 0, Errors: 0, Skipped: 0

```

Enfin il nous informe que le build de notre projet est réussi:

```
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------
[INFO] Total time:  3.150 s
[INFO] Finished at: 2022-11-15T11:27:02+01:00
[INFO] ------------------------------------------------------------------------
```

**Conclusion:**

Nous avons bien reussi à inclure l'intégralité de nos classes (Classe et Test) du TP2 dans notre TP3 .



## 3 Intégration continue




Gitlab permet de faire de l'intégration continue sur votre code.
Nous allons mettre en place un job permettant de réaliser la compilation,les test et le packaging à chaque commit en utilisant [Gitlab CI](https://about.gitlab.com/features/gitlab-ci-cd/)

### 3.1 Mettre en place une intégration continue en utilisant gitlab-ci

Liens utiles:
* [Gitlab CI](https://docs.gitlab.com/ce/ci/yaml/README.html#gitlab-ci-yml)

Sur la page d'acceuil de votre projet, à coté du bouton pour ajouter une licence, il y a un acces rapide pour créer à partir d'un template un fichier `.gitlab-ci.yml`.
On utilisera un template maven pour initialiser le descriptif des actions à réaliser.

* Désormais dans la partie CI/CD de votre projet vous pouvez voir vos pipelines en cours d'éxécution ou passé et leurs status.
* Le yml par defaut devrait faire echouer votre pipeline.
* Quelles est l'erreur ?

On n'a pas la bonne version du docker maeven dans le fichier **yml**.

La solution est de modifier la version du docker pour avoir la bonne version de java.

Après une recherche sur internet, on change et met `maven:3.8.3-openjdk-17` à la ligne image.

* Le script template proposé par defaut est relativement complexe.
* Pour la suite nous utiliserons le template suivant :

```yaml
variables:
  # This will supress any download for dependencies and plugins or upload messages which would clutter the console log.
  # `showDateTime` will show the passed time in milliseconds. You need to specify `--batch-mode` to make this work.
  MAVEN_OPTS: "-Dmaven.repo.local=.m2/repository -Dorg.slf4j.simpleLogger.log.org.apache.maven.cli.transfer.Slf4jMavenTransferListener=WARN -Dorg.slf4j.simpleLogger.showDateTime=true -Djava.awt.headless=true"
  # As of Maven 3.3.0 instead of this you may define these options in `.mvn/maven.config` so the same config is used
  # when running from the command line.
  # `installAtEnd` and `deployAtEnd` are only effective with recent version of the corresponding plugins.
  MAVEN_CLI_OPTS: "--batch-mode --errors --fail-at-end --show-version -DinstallAtEnd=true -DdeployAtEnd=true"

# Cache downloaded dependencies and plugins between builds.
# To keep cache across branches add 'key: "$CI_JOB_REF_NAME"'
cache:
  paths:
    - .m2/repository

#Definition des différentes étapes présent dans le pipeline
stages:
  - build
  - test

#Définition du job de compilation
compilation:
  image: maven:3.3.9-jdk-8
  stage: build
  script:
    - echo "A Completer";exit 1


validation:
  image: maven:3.3.9-jdk-8
  stage: test
  script:
      - echo "A Completer";exit 1
```

* Remplacez le `.gitlab-ci.yml` par celui-ci et completez le avec les commandes maven précédement utilisées pour réaliser la phase de build et de test

* Completez le `.gitlab-ci.yml` pour inclure un nouveau stage de packaging qui vas construire le jar de votre application

Nous avons modifié 2 élements donc notre fichier **.yml**:
* Pour la partie compilation on remplace le **echo** par `mvn compile` afin d'effectuer une compilation
* Pour la partie validation on remplace le **echo** par `mvn test` afin de compiler et faire les tests unitaires qui permettent de vérifier l'efficacité et le bon comportement de notre programme

#### 3.1.1 Badge

**Gilab** permet d'afficher dans votre readme le status de votre pipeline dynamiquement pour celà : 
* Rendez vous dans la partie [Settings > CI/CD > General pipelines settings](https://docs.gitlab.com/ee/user/project/pipelines/settings.html) de votre projet. A l'aide de la documentation sur les [badges](https://docs.gitlab.com/ee/user/project/pipelines/settings.html#badges) 
rajoutez un bdage indiquant le status de votre pipeline de build dans votre readme.

### 3.2 Couverture de code 

Nous allons ajouter un outil permettant de réaliser des statistiques sur la qualité des tests. Il sagit ici de [jacoco](http://www.eclemma.org/jacoco/) une librairie permettant de réaliser des statistiques sur le taux de couverture de code par les tests unitaires.

* Ce plugin lors de la compilation vas modifier votre code pour injecter du code permettant de savoir quelles lignes sont exécutées ou non.
    * Pour ce faire il faut rajouter dans votre **pom.xml**, dans la partie *build/pulgins*, la déclaration suivante :

```xml
<plugin>
    <groupId>org.jacoco</groupId>
    <artifactId>jacoco-maven-plugin</artifactId>
    <version>0.8.0</version>
    <executions>
        <execution>
            <id>default-prepare-agent</id>
            <goals>
                <goal>prepare-agent</goal>
            </goals>
        </execution>
    </executions>
</plugin>
```

* Nous allons rajouter au readme du projet un badge indiquant le % de code couvert.
    * Sur gitlab, dans les settings de la partie CI/CD dans General pipeline settings, vous trouverez une zone de saisie pour **Test coverage parsing**.
En effet il est nécessaire d'indiquer à **Gitlab CI** où trouver l'information sur le pourcentage de code couvert : `A regular expression that will be used to find the test coverage output in the job trace.`
    * Cette information se trouve dans le rapport généré par jacoco. Par defaut le rapport n'est pas généré. Il faut donc modifier le paramètrage du plugin pour lui demander de générer le rapport. 
Dans le code suivant on indique au plugin qu'il doit exécuter sa tache **report** lorsque de la phase **test** de maven.   

```xml
<execution>
    <id>default-report</id>
    <phase>test</phase>
    <goals>
        <goal>report</goal>
    </goals>
</execution>
```

* Le rapport est généré dans le repertoire target/site/jacoco sous la forme d'un fichier html.
    * Il faut dans la partie settings de votre CI indiquer l'expression réguliére permettant de retrouver le % de code couvert. Utilisez `Total.*?([0-9]{1,3})%`.
    * Ajoutez à votre `.gitlab-ci.yml` la commande permettant de faire apparaitre le contenu de ce fichier dans la log de votre job.
    
`Comment affichez vous l'information dans la log du job ?`

* Rajoutez en début de votre readme le badge indiquant le pourcentage de couverture de code.

### 3.3 Analyse de code avec Sonar
Nous allons mettre en place à chaque éxécution de notre pipeline une analyse sonar.

Le serveur sonar à utiliser se trouve à l'adresse suivante : [Sonar Cloud](https://sonarcloud.io)
Il faut créer un compte puis définit un token qui vas  être utilisé par vos scripts de CI pour éxécuté une analyse

* à la suite de la phase de test ajoutez dans votre job une analyse Sonar.
* Pour exécuter une analyse sonar il suffit de lancer la commande : 

```
mvn sonar:sonar -Dsonar.host.url=https://sonarcloud.io -Dsonar.login=TOKEN
```

* Généré un token pour votre user est utilisez votre token.
* Une fois la première analyse lancée, rendez vous sur l'application pour constater quels sont les anomalies détectées et les indicateurs de qualimétrie de votre code.
* Corrigez votre code en conséquence pour obtenir la meilleur note possible.
* Il est possible de spécifier directement dans le pom.xml l'adresse du serveur cible
    * pour ce faire on ajoutera dans la balise properties une entrée tel que : 
    
    ```xml
    <sonar.host.url>https://sonarcloud.io</sonar.host.url>
    ```
    * on peux alors appeler directement `mvn sonar:sonar -Dsonar.login=TOKEN` l'URL du serveur est prise dans les properties de votre projet maven
    
* Pour le login il est possible de faire de même, mais en terme de sécurité ce n'est pas une bonne idée d'indiquer le token d'acces dans vos sources
    * Gitlab-ci permet d'injecter de manière caché certaines propriétés [secret variables](https://gitlab.isima.fr/help/ci/variables/README#secret-variables)
    * Définissez une variable secrete contenant le login et utilisez la dans votre .gitlab-ci.yml   

