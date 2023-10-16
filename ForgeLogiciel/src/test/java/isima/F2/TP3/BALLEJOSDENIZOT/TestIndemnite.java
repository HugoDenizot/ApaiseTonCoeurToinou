package isima.F2.TP3.BALLEJOSDENIZOT;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.assertEquals;

// Cas a tester :
//      < 0
//      > 0
//      = 0

// Cas aux limites (en fonction de nous):
//      0, 10, 39, 60

// Cas d'erreur:
//      < 0 ? pas forcement une erreur nous on le gère en
//      renvoyant 0 pour le remboursement


@SpringBootTest
public class TestIndemnite {
    @Test
    public void CasLimite(){
        //test des cas limites
        Indemnite idtest = new Indemnite(0.0);
        assertEquals(0.0, idtest.calculIdemniteMain(), 0.001);
        idtest.setKilometre(10);
        assertEquals(15, idtest.calculIdemniteMain(), 0.001);
        idtest.setKilometre(39);
        assertEquals(15.6, idtest.calculIdemniteMain(), 0.001);
        idtest.setKilometre(60);
        assertEquals(20.43, idtest.calculIdemniteMain(), 0.001);
    }

    @Test
    public void CasErreur(){
        //test des cas limites
        Indemnite idtest = new Indemnite(-20);
        assertEquals(0.0, idtest.calculIdemniteMain(), 0.001);
    }

    @Test
    public void CasSujet(){
        //test des cas du sujet
        Indemnite ind1 = new Indemnite(-10);
        assertEquals(0.0, ind1.calculIdemniteMain(), 0.001);
        Indemnite ind2 = new Indemnite(0);
        assertEquals(0.0, ind2.calculIdemniteMain(), 0.001);
        Indemnite ind3 = new Indemnite(0.1);
        assertEquals(0.15, ind3.calculIdemniteMain(), 0.001);
        Indemnite ind4 = new Indemnite(17.123);
        assertEquals(6.8492, ind4.calculIdemniteMain(), 0.001);
        Indemnite ind5 = new Indemnite(39.5);
        assertEquals(21.725, ind5.calculIdemniteMain(), 0.001);
        Indemnite ind6 = new Indemnite(61);
        assertEquals(20.7705, ind6.calculIdemniteMain(), 0.001);
        Indemnite ind7 = new Indemnite(81);
        assertEquals(27.5805, ind7.calculIdemniteMain(), 0.001);
        Indemnite ind8 = new Indemnite(99);
        assertEquals(33.7095, ind8.calculIdemniteMain(), 0.001);
    }
}




