/*
SongRecord.h
Blake Eakin
CS 260
Project 1 
4/11/2019

SongRecord struct definition
*/
#pragma once

struct SongRecord {
	SongRecord* next;
	char* title;
	double length;
	long views;
	long likes;

	SongRecord();
	SongRecord(const SongRecord&);
	~SongRecord();
};
