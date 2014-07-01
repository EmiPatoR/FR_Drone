#ifndef MLDATA_H
#define MLDATA_H

#include <QString>
#include <opencv2/core/core.hpp>
#include "traintestsplit.h"

class MLData
{
public:
    MLData();
    virtual ~MLData();

    //read_csv
    int read_csv(QString filepath);
    int read_csv(std::string filepath);
    int read_csv(char* filepath);

    //set_response_idx
    int set_response_idx(int val);

    //get_values
    const cv::Mat* get_values(void);

    //get reponses
    const cv::Mat* get_responses(void);

    int get_responses_idx(void){
        return col_resp;
    }

    //set_train_test_split
    void set_train_test_split(const struct TrainTestSplit * spl);
    //get_train_sample
    const cv::Mat* get_train_sample_idx(void);
    //get_test_sample_idx
    const cv::Mat* get_test_sample_idx(void);
    //get_var_idx
    const cv::Mat* get_var_idx(void);

    const std::map<std::string,int>* get_class_labels_map(void){
        return &correspondances;
    }

    void set_delimiter(char val){
        separator = val;
    }

    char get_delimiter(void){
        return separator;
    }


protected:
    cv::Mat* valeurs;
    cv::Mat* responses;
    cv::Mat* train_sample;
    cv::Mat* test_sample;
    cv::Mat* m_vars;
    char separator; // séparateur
    int compteur;
    int col_resp; //colonne des réponses
    std::map<std::string,int> correspondances; // Correspondance labels -> id_classe
    int nb_col;
    int nb_lignes;
};

#endif // MLDATA_H
