/*
Kalman Track class for 
Kalman Muon Track Finder
Michalis Bachtis (UCLA)
Sep. 2017
*/

#ifndef L1MuKBMTrack_H
#define L1MuKBMTrack_H

#include "DataFormats/Candidate/interface/LeafCandidate.h"
#include "DataFormats/L1TMuon/interface/L1MuKBMTCombinedStub.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

class L1MuKBMTrack;
typedef std::vector<L1MuKBMTrack> L1MuKBMTrackCollection;
typedef BXVector<L1MuKBMTrack> L1MuKBMTrackBxCollection;

class L1MuKBMTrack : public reco::LeafCandidate {
public:
  L1MuKBMTrack();
  ~L1MuKBMTrack() override;
  L1MuKBMTrack(const L1MuKBMTCombinedStubRef&, int, double);

  //UnConstrained curvature at station 1
  double curvatureAtMuon() const;
  //unconstrained phi at station 1
  int phiAtMuon() const;
  //unconstrained phiB at station 1
  double phiBAtMuon() const;
  //Constrained curvature at vertex
  double curvatureAtVertex() const;
  //constrained phi at the vertex
  int phiAtVertex() const;
  //Impact parameter as calculated from the muon track
  double dxy() const;
  //Unconstrained curvature at the Muon systen
  double curvature() const;
  //Unconstrained phi at the Muon systen
  int positionAngle() const;
  //Unconstrained bending angle at the Muon systen
  double bendingAngle() const;
  //Coarse eta caluclated only using phi segments
  int coarseEta() const;
  //Approximate Chi2 metric
  int approxChi2() const;
  int trackCompatibility() const;
  float met_bxm9() const;
  float met_bxm8() const;
  float met_bxm7() const;
  float met_bxm6() const;
  float met_bxm5() const;
  float met_bxm4() const;
  float met_bxm3() const;
  float met_bxm2() const;
  float met_bxm1() const;
  float met_bx0() const;


  double eLoss() const;
  float beta() const;

  //Returns the entire PhiB collection
  const std::vector<double>& trackPhiBCollection() const { return trackPhiB_; }
  //returns only the specific PhiB
  double trackPhiB(int station) const;

  //Approximate Chi2 metric
  int hitPattern() const;
  //step;
  int step() const;
  //sector;
  int sector() const;
  //wheel
  int wheel() const;
  //quality
  int quality() const;

  //unconstrained pt
  float ptUnconstrained() const;

  //fine eta
  int fineEta() const;
  bool hasFineEta() const;

  //BX
  int bx() const;

  //rank
  int rank() const;

  //Associated stubs
  const L1MuKBMTCombinedStubRefVector& stubs() const;

  //get Kalman gain
  const std::vector<float>& kalmanGain(unsigned int) const;
  
  //const std::vector<float>& similarityMatrix(unsigned int) const;


  //get covariance
  const std::vector<double>& covariance() const;

  //get residual
  int residual(uint) const;
  const std::vector<int>& residualVector() const { return residuals_; }
  const std::vector<double>& innovationVector() const { return innovations_; }



  //check ogverlap
  bool overlapTrack(const L1MuKBMTrack&) const;

  bool operator==(const L1MuKBMTrack& t2) const {
    if (this->stubs().size() != t2.stubs().size())
      return false;
    for (unsigned int i = 0; i < this->stubs().size(); ++i) {
      const L1MuKBMTCombinedStubRef& s1 = this->stubs()[i];
      const L1MuKBMTCombinedStubRef& s2 = t2.stubs()[i];
      if (s1->scNum() != s2->scNum() || s1->whNum() != s2->whNum() || s1->stNum() != s2->stNum() ||
          s1->tag() != s2->tag())
        return false;
    }
    return true;
  }

  //Set coordinates general
  void setCoordinates(int, double, int, double);

  //Set coordinates at vertex
  void setCoordinatesAtVertex(double, int, double);

  //Set coordinates at muon
  void setCoordinatesAtMuon(double, int, double);

  //Set eta coarse and pattern
  void setCoarseEta(int);

  //Set phi hit pattern
  void setHitPattern(int);

  //Set chi2 like metric
  void setApproxChi2(int);
  void setTrackCompatibility(int);
  void setMetBxm9(float);
  void setMetBxm8(float);
  void setMetBxm7(float);
  void setMetBxm6(float);
  void setMetBxm5(float);
  void setMetBxm4(float);
  void setMetBxm3(float);
  void setMetBxm2(float);
  void setMetBxm1(float);
  void setMetBx0(float);

  void seteLoss(double);
  void setBeta(float);

  //Set PhiB in the vector previously declared
  void setTrackPhiB(int station, double phiB);

  //Set floating point coordinates for studies
  void setPtEtaPhi(double, double, double);
  void setPtUnconstrained(float);

  //Add a stub
  void addStub(const L1MuKBMTCombinedStubRef&);

  //kalman gain management
  void setKalmanGain(
      unsigned int step, double K, float a1, float a2, float a3, float a4 = 0, float a5 = 0, float a6 = 0);

  //set covariance
  void setCovariance(const CovarianceMatrix&);

  //set fine eta
  void setFineEta(int);

  //set rank
  void setRank(int);

  //set residual
  void setResidual(uint, int);
  void setInnovationPhiB(uint, double);

private:
  //Covariance matrix for studies
  std::vector<double> covariance_;

  L1MuKBMTCombinedStubRefVector stubs_;

  //vertex coordinates
  double curvVertex_ = 0;
  int phiVertex_ = 0;
  double dxy_ = 0;

  //muon coordinates
  double curvMuon_ = 0.0;
  int phiMuon_ = 0;
  double phiBMuon_ = 0.0;

  //generic coordinates
  double curv_ = 0.0;
  int phi_ = 0;
  double phiB_ = 0.0;
  //common coordinates
  int coarseEta_ = 0;

  //Approximate Chi2 metric
  int approxChi2_ = 0;
  int trackCompatibility_ = 0;
  float met_bxm9_ = 0;
  float met_bxm8_ = 0;
  float met_bxm7_ = 0;
  float met_bxm6_ = 0;
  float met_bxm5_ = 0;
  float met_bxm4_ = 0;
  float met_bxm3_ = 0;
  float met_bxm2_ = 0;
  float met_bxm1_ = 0;
  float met_bx0_ = 0;

  double eLoss_ = 0.0;
  float beta_ = 1.0;

  std::vector<double> trackPhiB_ = {-9999, -9999, -9999, -9999};


  //phi bitmask
  int hitPattern_ = 0;

  //propagation step
  int step_ = 0;

  //sector
  int sector_ = 0;
  //wheel
  int wheel_ = 0;

  //quality
  int quality_ = 0;

  //Fine eta
  int fineEta_ = 0;

  //has fine eta?
  bool hasFineEta_ = false;

  //BX
  int bx_ = 0;

  //rank
  int rank_ = 0;

  //Unconstrained floating point pt
  float ptUnconstrained_ = 0;

  //Kalman Gain for making LUTs
  std::vector<float> kalmanGain0_;
  std::vector<float> kalmanGain1_;
  std::vector<float> kalmanGain2_;
  std::vector<float> kalmanGain3_;

  std::vector<int> residuals_;
  std::vector<double> innovations_;
};

#endif
