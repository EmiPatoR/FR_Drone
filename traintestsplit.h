#ifndef TRAINTESTSPLIT_H
#define TRAINTESTSPLIT_H


struct TrainTestSplit
{
    TrainTestSplit();
    TrainTestSplit( int train_sample_count, bool mix = true);
    TrainTestSplit(float train_sample_portion, bool mix = true);
    TrainTestSplit( double train_sample_portion, bool mix = true);

    union
    {
        int count;
        float portion;
    } train_sample_part;
    int train_sample_part_mode;

    bool mix;
};

#endif // TRAINTESTSPLIT_H
