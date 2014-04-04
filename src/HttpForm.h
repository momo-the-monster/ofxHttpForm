
#pragma once
#include <iostream>
#include <vector>
#include <map>

struct FormContent{
	string path;
	string contentType;
};

struct HttpForm{

		HttpForm(){
			url = "";
		}

		HttpForm( string url_ ){
			url = url_;
		}
		
		~HttpForm(){
			clearFormFields();
		}

		void setURL(string url_){
			url = url_;			
		}
	
		void addFormField(string ID, string value){
			formIds.push_back( ID );
			formValues.push_back( value );
		}

		void addJson( string data ) {
			jsonData = data;
		}
		
		void clearFormFields(){
			formIds.clear();
			formValues.clear();
			formFiles.clear();
		}
		
		void addFile(string fieldName, string path, string mimeType = "text/plain"){
			FormContent f;
			f.path = ofToDataPath(path);
			f.contentType = mimeType;
			formFiles[fieldName] = f;
		}

		string getFieldValue(string id){
			for(unsigned int i=0;i<formIds.size();i++){
				if(formIds[i]==id) return formValues[i];
			}
			return "";
		}

		string url;
		string jsonData;
		vector <string> formIds;
		vector <string> formValues;
		std::map< string, FormContent >formFiles;
};

