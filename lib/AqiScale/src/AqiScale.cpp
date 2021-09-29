#include "AqiScale.h"

AqiScale::AqiScale AqiScale()
{
    bon.description = "Bon";
    bon.impact = "La qualité de l’air est considérée comme satisfaisante et la pollution de l’air pose peu ou pas de risque";
    bon.warning = "Aucune";
    bon.bkgColor = "#00ff00";
    bon.textColor = "#FFFFFF";

    acceptable.description = "Acceptable";
    acceptable.impact = "La qualité de l’air est acceptable; cependant, pour certains polluants, il peut y avoir un problème de santé modéré pour un très petit nombre de personnes qui sont inhabituellement sensibles à la pollution atmosphérique";
    acceptable.warning = "Les enfants et les adultes actifs, ainsi que les personnes souffrant de maladies respiratoires, telles que l’asthme, devraient limiter les efforts prolongés à l’extérieur";
    acceptable.bkgColor = "#ffff00";
    acceptable.textColor = "#FFFFFF";

    mauvaisGroupeSensible.description = "Mauvais pour les groupes sensibles";
    mauvaisGroupeSensible.impact = "Les membres de groupes sensibles peuvent subir des effets sur la santé. Le grand public ne sera probablement pas affecté";
    mauvaisGroupeSensible.warning = "Les enfants et les adultes actifs, ainsi que les personnes souffrant de maladies respiratoires, telles que l’asthme, devraient limiter les efforts prolongés à l’extérieur.";
    mauvaisGroupeSensible.bkgColor = "#ff9933";
    mauvaisGroupeSensible.textColor = "#FFFFFF";

    mauvaisPourSante.description = "Mauvais pour la santé";
    mauvaisPourSante.impact = "Tout le monde peut commencer à ressentir des effets sur la santé; les membres de groupes sensibles peuvent subir des effets plus graves sur la santé.";
    mauvaisPourSante.warning = "Les enfants et les adultes actifs, ainsi que les personnes souffrant de maladies respiratoires, telles que l’asthme, devraient éviter les efforts prolongés à l’extérieur; tout le monde, en particulier les enfants, devrait limiter les efforts prolongés à l’extérieur.";
    mauvaisPourSante.bkgColor = "#ff0000";
    mauvaisPourSante.textColor = "#FFFFFF";

    tresMauvais.description = "Très mauvais pour la santé";
    tresMauvais.impact = "Avertissements sanitaires des conditions d’urgence. La population entière est plus susceptible d’être touchée.";
    tresMauvais.warning = "Les enfants et les adultes actifs, ainsi que les personnes souffrant de maladies respiratoires, comme l’asthme, devraient éviter tout effort extérieur; tout le monde, en particulier les enfants, devrait limiter les efforts à l’extérieur.";
    tresMauvais.bkgColor = "#993366";
    tresMauvais.textColor = "#FFFFFF";

    Dangereux.description = "Dangereux";
    Dangereux.impact = "Alerte santé: tout le monde peut subir des effets sanitaires plus graves.";
    Dangereux.warning = "Tout le monde devrait éviter tout effort extérieur.";
    Dangereux.bkgColor = "#4d1932";
    Dangereux.textColor = "#FFFFFF";
}

AqiInfo AqiScale::getAQILabelFromPM25(float pm25Value)
{
    if(pm25Value <= 11)
    {
        return bon;
    }
    else if(pm25Value <= 34)
    {
        return acceptable;
    }
    else if(pm25Value <= 54)
    {
        return mauvaisGroupeSensible;
    }
    else if(pm25Value <= 149)
    {
        return mauvaisPourSante;
    }
    else if(pm25Value <= 249)
    {
        return tresMauvais;
    }
    else
    {
        return Dangereux;
    }
}