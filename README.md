# JucePlugins

Ce répertoire regroupe le code des plugins développés avec le framework [Juce](https://www.juce.com/) durant le cours [paccpp2](https://github.com/paccpp/paccpp2).

## Installation

Pour compliler les plugins de ce répertoire vous pouvez suivre le début de ce [tutoriel](https://www.juce.com/doc/tutorial_create_projucer_basic_plugin):

 - Téléchargez ce répertoire.
 - Téléchargez le framework *Juce* à partir de ce [lien](https://www.juce.com/get-juce).
 - Extraire le packet puis le placer quelque part.
 - Téléchargez le SDK pour créer des VST [ici](https://www.steinberg.net/en/company/developers.html) et placez le quelque part.
 - Ouvrez ensuite l'application **Projucer**.
 - Ajouter le path vers le dossier *VST3 SDK* que vous avez téléchargé dans les réglages de path.
 - Ouvrez ensuite un des projets de ce répertoire (ex: AmplitudeModulation.jucer).
 - Vérifiez ensuite que le path de tous les modules pointent bien vers le dossier de module de Juce.
 - Générer votre projet et ouvrez le en cliquant dans l'onglet *Config* sur *Save Project and Open in IDE...*.
 - Compilez le plugin avec l'IDE sélectionné.

## Plugins

| Name      | description |
|-----------|-------------|
|[AmplitudeModulation](AmplitudeModulation) | A simple amplitude modulation plugin |

## Liens

- [Tutoriels](https://www.juce.com/tutorials)
- [API](https://www.juce.com/doc/classes)
- [Forum](https://forum.juce.com/)
