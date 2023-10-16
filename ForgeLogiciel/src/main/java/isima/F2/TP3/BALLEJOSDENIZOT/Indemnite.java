package isima.F2.TP3.BALLEJOSDENIZOT;

public class Indemnite {
    private double nbKilometre;

    public Indemnite(double nbKilometre){
        this.nbKilometre = nbKilometre;
    }

    public void setKilometre(double nbKilometre){
        this.nbKilometre = nbKilometre;
    }

    public double getKilometre(){
        return this.nbKilometre;
    }

    private double calculateParKm(double valeurParKm){
        return this.getKilometre() * valeurParKm;
    }

    private double calculPlus60(){
        return (this.getKilometre() / 20.0) * 6.81;
    }

    public double calculIdemniteMain(){
        double retour = 0.0;

        if(this.getKilometre() > 0) {
            if (this.getKilometre() <= 10.0) {
                retour = this.calculateParKm(1.50);
            } else if (this.getKilometre() <= 39.0) {
                retour = this.calculateParKm(0.40);
            } else if (this.getKilometre() < 60.0) {
                retour = this.calculateParKm(0.55);
            } else {
                retour = this.calculPlus60();
            }
        }
        return retour;
    }
}
