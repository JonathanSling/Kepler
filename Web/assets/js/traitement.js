//Fonction d'importation de fichier
function ImportFile() {

    aligncalc = false;
    let p = document.getElementById("File").querySelectorAll("p")[0]; //élément texte pour écrire le nom du fichier

    //creation d'un élément input pour charger le fichier
    var input = document.createElement('input');
    input.type = 'file';
    input.click();

    //dès que le fichier a chargé on créée un reader qui lit le fichier
    input.onchange = () => {
        p.innerHTML = "Chargement ...";
        let reader = new FileReader();
        reader.readAsText(input.files[0]);
        reader.onload = (() => { //dès que le fichier est lu et enregistré dans le reader
            processJson(reader); //on process le JSON
            p.innerHTML = "file : " + input.files[0]['name']; //on ecrit dans le html le nom du fichier choisi
        });
    }

}

//Fonction qui traite le JSON
function processJson(file) {
    const json = JSON.parse(file.result); //transforme le resultat de text a JSON

    let key = Object.keys(json); //variable key qui contient tout les noms de planètes
    for (i in key) { //pour chaque planète
        raw[i] = json[key[i]]; //varaible data raw (pour les alignements)
        traj[i] = trajectoires(raw[i]); //variable traj (pour les positions à l'echelle du canvas)
        speed[i] = []
        speed[i] = Qspeed(raw[i]); //variable speed (pour les vitesses quadratiques)
    }

    htmlSet(key);
    setup();
}

//Fonction qui calcul les positions (each) avec une règle de trois pour chaque échelle (i)
function trajectoires(Tdata) {
    let result = [];
    for (each in Tdata) {
        result[each] = [];
        for (let i = 1; i <= scale; i++) {
            result[each][i] = [];
            result[each][i][0] = ((Tdata[each][0][0] * i * 35) / 8e+11) + 400;
            result[each][i][1] = -((Tdata[each][0][1] * i * 35) / 8e+11) + 200;
        }
    }
    return result;
}

//fonction qui calcule sur toutes les positions la vitesse quadratique de l'astre
function Qspeed(sp) {
    let result = []
    for (i in sp) {//pour chaque points dans sp
        result[i] = Math.sqrt(sp[i][1][0] * sp[i][1][0] + sp[i][1][1] * sp[i][1][1] + sp[i][1][2] * sp[i][1][2]).toFixed(0); //racine carré des vitesse en x,y et z au carré
    }
    return result;
}

//Fonction qui ajoute dans la variable globale "tminus" les positions ou les planètes sélectionnées (avec les checkbox) sont alignées
function calculAlign() {
    let line;
    let PtoP;
    tminus = [];
    
    //recupère les planetes checké dans le menu alignement
    let li = ul2.querySelectorAll("li");
    let Plan_arr = []
    for (let i = 0; i<li.length-1; i++) {
        if (li[i].querySelectorAll("input")[0].checked) { //si checkbox checked alors on push la planete dans l'array 
            Plan_arr.push(i);
        }
    }
    
    for (let j = 0; j < raw[0].length - 1; j++) {
        line = (raw[Plan_arr[0]][j][0][1] - 200) / (raw[Plan_arr[0]][j][0][0] - 400); //calcul le coefficient directeur entre le soleil et le premier astre de ceux récupérés
        for (let i = 1; i < Plan_arr.length; i++) {
            PtoP = (raw[Plan_arr[i]][j][0][1] - 200) / (raw[Plan_arr[i]][j][0][0] - 400); //calcul le coefficient directeur entre le soleil et l'astre de la boucle
            if ((Math.round(line*50))/50 != (Math.round(PtoP*50))/50) { // si coeff différent alors astres non-alignés
                break;
            } else if (i == Plan_arr.length - 1) { //sinon ajout de la position dans la variable globale tminus
                tminus.push(j);
            }
        }
    }

    aligncalc = true;
}

//Fonction boolean qui vérifie si aucun des éléments de ul a la classe "active"
function classEmpty() {
    li = ul.querySelectorAll("li");
    for (let j = 0; j < li.length; j++) {
        if (li[j].classList.contains('active')) //pour chaque si un li contient active alors => 0
            return 0;
    }
    return 1;
}

//Fonction qui créée 600 étoiles(positions de points) et qui les stocke dans la variable globale stars
function generateStar() {
    for (let j = 0; j < 600; j++) {
        stars[j] = {
            'x': Math.floor(Math.random() * 800), 'y': Math.floor(Math.random() * 400)
        };
    }
}

//Fonction qui renvoie la prochaine position à laquelle les planètes s'aligneront
function alignPos() {
    for (i in tminus) {
        if ((position - tminus[i]) < 0) {
            return position - tminus[i];
        }
    }
    return "+∞"; //si il n'y a pas de prochaine position alors on renvoie +∞
}