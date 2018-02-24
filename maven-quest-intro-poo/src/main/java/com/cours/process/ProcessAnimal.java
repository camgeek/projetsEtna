/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.cours.process;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Pattern;
import java.util.Date;

import com.cours.entities.Animal;

/**
 *
 * @author elhad
 */
public class ProcessAnimal {

    public ArrayList<Animal> loadAnimals() {
    	
    	ArrayList<Animal> animals = new ArrayList<Animal>();
    	ArrayList<String> mots = new ArrayList<String>();
    	Date nowDate = new Date();
    	nowDate.toInstant();
    	
    	mots.add("lyon");
    	mots.add("éléphant");
    	mots.add("chien");
    	mots.add("chat");
    	
    	for (int i=1;i <= 11;i++)
    	{
    		int temp = (int) ((Math.random() * (4)));
    		animals.add(new Animal(i, mots.get(temp), (i*5), nowDate, "rouge", 4, true));
    	}
    	return animals;
    }

    public ArrayList<Animal> loadAnimalsFile() {
    	
    	ArrayList<Animal> animals = new ArrayList<Animal>();
    	try {

            File f = new File("animaux.txt");
            BufferedReader b = new BufferedReader(new FileReader(f));
            String readLine = "";
        	SimpleDateFormat formatterDMY = new SimpleDateFormat("dd/MM/yyyy");
        	
            while ((readLine = b.readLine()) != null) {
            	String[] tokens = readLine.split(Pattern.quote(","));
                //System.out.println(Arrays.toString(tokens));
            	int id = Integer.parseInt(tokens[0].trim());
            	int poids = Integer.parseInt(tokens[2].trim());
            	int pattes =  Integer.parseInt(tokens[5].trim());
            	boolean carni = Boolean.parseBoolean(tokens[6].trim());
            	try {
					Date dateAni = formatterDMY.parse(tokens[3]);
	            	animals.add(new Animal(id, tokens[1], poids, dateAni , tokens[4], pattes, carni));
				} catch (ParseException e) {
					e.printStackTrace();
				}	
            }

        } catch (IOException e) {
            e.printStackTrace();
        }   	
    	return animals;
    }

    public Double calculMoyennePoidsAnimaux(List<Double> listPoids) {

    	double sum = 0.0;
    	
    	for(int i=0;i < listPoids.size();i++) {
    		sum =+ listPoids.get(i);
    	}
    	
        return sum/listPoids.size();
    }

    public Double calculEcartTypePoidsAnimaux(List<Double> listPoids) {

    	 double sum = 0.0, standardDeviation = 0.0;

         for(double num : listPoids) {
             sum += num;
         }

         double mean = sum/10;

         for(double num: listPoids) {
             standardDeviation += Math.pow(num - mean, 2);
         }

         return Math.sqrt(standardDeviation/10);
    }

}
