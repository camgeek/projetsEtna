/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.cours.entities;

import java.util.Comparator;

/**
 *
 * @author elhad
 */
public class ComparatorAnimal implements Comparator<Animal> {

    private int compareType = 0;

    public ComparatorAnimal() {

    }

    public ComparatorAnimal(int compareType) {
        this.compareType = compareType;
    }

    @Override
    public int compare(Animal animal1, Animal animal2) {
    	switch (this.compareType) {
		case 1:
			return new Integer(animal1.getIdAnimal()).compareTo(animal2.getIdAnimal());
		case 2:
			return animal1.getNom().compareTo(animal2.getNom());
		case 3:
			return animal1.getDateNaissance().compareTo(animal2.getDateNaissance());
		case 4:
			return new Double(animal2.getPoids()).compareTo(animal1.getPoids());
		case 5:
			return animal1.getCouleur().compareTo(animal2.getCouleur());
		default:
			break;
		}
    	return 0;
    }
}
