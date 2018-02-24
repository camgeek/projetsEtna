/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.cours.entities;

import java.util.Date;

/**
 *
 * @author elhad
 */
public class Animal {

	int idAnimal;
	String nom;
	double poids;
	Date dateNaissance;
	String couleur;
	int nombrePattes;
	boolean estCarnivore;

	public Animal(int idAnimal, String nom, double poids, Date dateNaissance, String couleur, int nombrePattes,
			boolean estCarnivore) {
		super();
		this.idAnimal = idAnimal;
		this.nom = nom;
		this.poids = poids;
		this.dateNaissance = dateNaissance;
		this.couleur = couleur;
		this.nombrePattes = nombrePattes;
		this.estCarnivore = estCarnivore;
	}

	public void marcher() {

	}

	public void description() {

	}

	@Override
	public String toString() {
		return "Animal [idAnimal=" + idAnimal + ", nom=" + nom + ", poids=" + poids + ", dateNaissance=" + dateNaissance
				+ ", couleur=" + couleur + ", nombrePattes=" + nombrePattes + ", estCarnivore=" + estCarnivore + "]\n";
	}

	@Override
	//La méthode equals() vérifie l'égalité de deux objets : son rôle est de vérifier si deux instances 
	//sont sémantiquement équivalentes même si ce sont deux instances distinctes.
	public boolean equals(Object obj) {
		Animal other = (Animal) obj;
		if (idAnimal != other.idAnimal) {
			return false; }
		return true;
	}

	@Override
	//La méthode hashCode() retourne valeur de hachage calculée sur l'instance d'un objet.
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + idAnimal;
		long temp;
		temp = Double.doubleToLongBits(poids);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		return result;
	}

	public int getIdAnimal() {
		return idAnimal;
	}

	public void setIdAnimal(int idAnimal) {
		this.idAnimal = idAnimal;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public double getPoids() {
		return poids;
	}

	public void setPoids(double poids) {
		this.poids = poids;
	}

	public Date getDateNaissance() {
		return dateNaissance;
	}

	public void setDateNaissance(Date dateNaissance) {
		this.dateNaissance = dateNaissance;
	}

	public String getCouleur() {
		return couleur;
	}

	public void setCouleur(String couleur) {
		this.couleur = couleur;
	}

	public int getNombrePattes() {
		return nombrePattes;
	}

	public void setNombrePattes(int nombrePattes) {
		this.nombrePattes = nombrePattes;
	}

	public boolean isEstCarnivore() {
		return estCarnivore;
	}

	public void setEstCarnivore(boolean estCarnivore) {
		this.estCarnivore = estCarnivore;
	}
	
	

}
