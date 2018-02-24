/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.cours.main;

import com.cours.entities.Animal;
import com.cours.entities.ComparatorAnimal;
import com.cours.process.ProcessAnimal;

import java.io.Console;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/**
 *
 * @author elhad
 */
public class Main {

	private static final Log log = LogFactory.getLog(Main.class);

	/**
	 * @param args
	 *            the command line arguments
	 */
	public static void main(String[] args) {
		// TODO code application logic here
		// testNombres();
		// testChaines();
		// triNombres();
		//calculFactorielItterative();
		//System.out.print(calculFactorielRecursive(5));
		ProcessAnimal process = new ProcessAnimal();
		//process.loadAnimals();
		//process.loadAnimalsFile();
		List<Animal> animals;
		animals = process.loadAnimalsFile();
		List<Double> listPoids = new ArrayList<Double>();
		for (Animal animal : animals) {
			listPoids.add(animal.getPoids());
		}
		
		System.out.println(process.calculMoyennePoidsAnimaux(listPoids));
		System.out.println(process.calculEcartTypePoidsAnimaux(listPoids));
		
		//6) Implémentez un tri d’animaux par l’attribut « idAnimal » de l’animal.
			Collections.sort(animals, new ComparatorAnimal(1));
		//7) Implémentez un tri d’animaux par l’attribut « nom » de l’animal.
			Collections.sort(animals, new ComparatorAnimal(2));
			FileWriter fw;
			try {
				fw = new FileWriter("animauxParNom.txt");
				for (Animal animal : animals) {
					fw.write(animal.toString());
				}
			 
				fw.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		//8) Implémentez un tri d’animaux par l’attribut « poids » de l’animal.
			Collections.sort(animals, new ComparatorAnimal(4));
			try {
				fw = new FileWriter("animauxParPoids.txt");
				for (Animal animal : animals) {
					fw.write(animal.toString());
				}
			 
				fw.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		//9) Implémentez un tri d’animaux par l’attribut « couleur » de l’animal.
			Collections.sort(animals, new ComparatorAnimal(5));
			
	}

	public static void testNombres() {
		Scanner sc = new Scanner(System.in);

		System.out.print("Entrez un nombre entier: ");
		int nb = sc.nextInt();
		System.out.print(nb);
		System.out.print(" le nombre est");

		if (nb == 0) {
			System.out.print(" nul");
			return;
		} else if (nb > 0) {
			System.out.print(" positif");
		} else if (nb < 0) {
			System.out.print(" negatif");
		}
		System.out.print(" et");
		if (nb % 2 == 0) {
			System.out.print(" pair");
		} else {
			System.out.print(" impair");
		}
	}

	public static void testChaines() {
		Scanner sc = new Scanner(System.in);

		System.out.println("1er chaine : ");
		String str1 = sc.nextLine();
		System.out.println("2er chaine : ");
		String str2 = sc.nextLine();

		if (str1.compareTo(str2) == 0) {
			System.out.println("Les deux chaînes sont identiques");
		} else if (str1.compareTo(str2) > 0) {
			System.out.println("La première chaîne est supérieure à la deuxième");
		} else {
			System.out.println("La deuxième chaîne est supérieure à la première");
		}
	}

	public static void triNombres() {

		int[] tabs = new int[100];

		for (int i = 0; i < tabs.length; i++) {
			tabs[i] = (int) ((Math.random() * (100)));
		}
		System.out.println(Arrays.toString(tabs));
		
		boolean permut = false;
		int tampon = 0;
		int i;
		while (!permut) {
			permut = true;
			for (i = 0; i < tabs.length - 1; i++) {
				if (tabs[i] > tabs[i + 1]) {
					tampon = tabs[i];
					tabs[i] = tabs[i + 1];
					tabs[i + 1] = tampon;
					permut = false;
				}
			}
		}
		
		System.out.println(Arrays.toString(tabs));

	}

	/**
	 * Attention pour simplifier l'exercice on ne mettre que de petit nombre entier
	 * inferieur à 1000. Sinon on risque de depasser la limite prévu pour le type
	 * int. Vous pouvez donc utiliser le type entier int.
	 */
	public static void calculFactorielItterative() {		
		Scanner sc = new Scanner(System.in);

		System.out.print("Entrez un nombre: ");
		int nb = sc.nextInt();
		int res = 1;
		int j = 0;
		for (int i=1;i < nb;i++)
		{
			j = i + 1;
			if (j <= nb) {
			res = res * j;}
		}	
		System.out.println("resultat : "+res);
	}

	/**
	 * Attention pour simplifier l'exercice on ne mettre que de petit nombre entier
	 * inferieur à 1000. Sinon on risque de depasser la limite prévu pour le type
	 * int. Vous pouvez donc utiliser le type entier int.
	 */
	public static int calculFactorielRecursive(int nb) {
		if (nb > 1) {
			return nb * calculFactorielRecursive(nb - 1);
		}else {
			return 1;
		}
	}
}
