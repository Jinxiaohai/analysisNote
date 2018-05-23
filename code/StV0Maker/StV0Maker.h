#ifndef StV0Maker_def
#define StV0Maker_def

#include "StMaker.h"
#include "TString.h"
#include "StPhysicalHelixD.hh"
#include "StThreeVectorD.hh"

class StMuDstMaker;
class StMuTrack;
class TFile;
class TTree;
class TH1F;
class TH2F;

#include "StV0Type.h"
#include "StV0Dst.h"

///
/// \brief The StV0Maker class
/// The StV0Maker class for read daq data to generate V0 data.
/// it is the main source.
/// \see StMaker
class StV0Maker : public StMaker {

 private:
  // Make MuDst pointer available to member functions
  StMuDstMaker* mMuDstMaker;

  ///
  /// \brief mV0Type
  /// V0 type.(Lambda = 0 and AntiLambda = 1)
  StV0Type mV0Type;

  ///
  /// \brief mRotate
  /// switch for rotating the coordinates and momenta (in transverse direction)
  /// of one daughter for background estimation. (estimate the background.)
  bool mRotate;
  bool mSameSignPlus;   ///< same sign plus
  bool mSameSignMinus;  ///< same sign minus
  bool mDcaAlgoLong;    ///< Dca algorithm huilong

  ///
  /// \brief V0 type related constants
  /// \section V0 constants
  Float_t mMassV0;  ///< The mass of V0
  Float_t mMass1;   ///< The mass of first daughter
  Float_t mMass2;   ///< The mass of second daughter
  Int_t mChargeV0;  ///< The charge of V0
  Int_t mCharge1;   ///< The charge of first daughter
  Int_t mCharge2;   ///< The charge of second daughter

  ///
  /// \brief cut parameters for V0 analysis
  /// \section cut parameters
  /// LeEq is less equal ??????
  /// Gr is grater ??????
  float cutAbsVertexZLeEq;  ///< Abs Vertex Z LeEq
  int cutNHitsGr;           ///< N hits gr ???? (what is Gr ?????)
  int cutNHitsDedxGr;       ///< N hits dEdX gr ????
  float cutPtGrEq;          ///< Pt Gr Eq ????

  float cutAbsNSigma2Le;  ///< Abs N sigma 2 Le (what is Le ????)
  float cutDca1GrEq;      ///< Dca1 GrEq ?????
  float cutDca2GrEq;      ///< Dca2 GrEq ?????

  float cutDca1to2LeEq;                ///< Dca 1 to 2 less equal
  float cutV0MassWidthLeEq;            ///< V0 Mass Width less equal
  float cutDauPtArmLeEq;               ///< daughter pt arm less eqaul ????
  float cutAbsDausPtShoulderDiffLeEq;  ///< Abs daughter Pt shoulder diff less
  /// equal
  float cutDau1DecAngGr;          ///< daughter 1 ?????
  float cutDau2DecAngGr;          ///< daughter 2 ?????
  float cutV0rdotpGr;             ///< V0 r dot p grater ???
  float cutDcaV0Le;               ///< Dca V0 less ????
  float cutV0DecLenGrEq;          ///< V0 Dec length grater equal ????
  float cutDau1Dau2Ang3DLe;       ///< daughter1 daughter2 angle 3D less ????
  float cutDau1Dau2DipAngDiffLe;  ///< daughter1 daughter2 Dip Angle difference
  /// less ????

  double RotDegree;  ///< rotation degree ????

  // histograms (mostly for QA purpose)
  TH1F* hNPrimVertex;
  TH1F* hVertexZ;
  TH1F* hVertexZdiff;
  TH1F* hNRefMult;
  TH1F* hSelectNRefMult;
  TH1F* hMagneticField;

  TH2F* hnSigmaProton;
  TH2F* hnSigmaPion;
  TH2F* hnSigmaKaon;
  TH2F* hdEdxP;
  TH2F* hDcaP;
  TH2F* hMassP;
  TH2F* hInvBetaP;
  TH2F* hdau1dEdxP;
  TH2F* hdau2dEdxP;
  TH2F* hdau1ZP;
  TH2F* hdau2ZP;
  TH2F* hdau1MassP;
  TH2F* hdau2MassP;
  TH2F* hdau1InvBetaP;
  TH2F* hdau2InvBetaP;
  TH2F* hdau1DiffInvBetaP;
  TH2F* hdau2DiffInvBetaP;

  TH1F* hInvMass;

  // dEdx information of tracks.
  ///
  /// \brief dEdX
  /// the energy loss
  double dedx_dau1_th[11901];
  double dedx_dau2_th[11901];

  // files related
  ///
  /// \brief mHistogramOutputFileName
  /// Name of the histogram output file
  TString mHistogramOutputFileName;
  ///
  /// \brief mV0TreeOutputFileName
  /// Name of the V0 tree output file
  TString mV0TreeOutputFileName;
  ///
  /// \brief histogram_output
  /// Histograms output file pointer
  TFile* histogram_output;
  ///
  /// \brief v0tree_output
  /// V0 tree output file pointer
  TFile* v0tree_output;
  ///
  /// \brief mV0Tree
  /// V0 tree
  TTree* mV0Tree;
  ///
  /// \brief mV0Dst
  /// V0 event (picoDst), to fill the tree.
  StV0Dst mV0Dst;

  // statistic information
  UInt_t mEventsProcessed;  //  Number of Events read and processed

  // some diagnosing variables
  Float_t mTestVZ;
  UInt_t mTestNTrack;
  bool mPassEventCut;

  // temporary variables (put here for performance consideration)
  vector<StMuTrack*> mDauVec1;
  vector<StMuTrack*> mDauVec2;
  vector<double> mDauDcaVec1;
  vector<double> mDauDcaVec2;
  vector<double> mDauZVec1;
  vector<double> mDauZVec2;
  vector<double> mDauMassVec1;
  vector<double> mDauMassVec2;
  vector<double> mDauBetaVec1;
  vector<double> mDauBetaVec2;
  vector<double> mDauDiffInvBetaVec1;
  vector<double> mDauDiffInvBetaVec2;

  // private member functions
  void initParam();  // initialize parameters
  void initConst();  // initialize constants for v0type
  void initHisto();  // book histograms
  void initTree();   // book tree

 protected:
  // I do not expect some class inherits this maker!

 public:
  StV0Maker(StMuDstMaker* maker, const char* name);  // Constructor
  virtual ~StV0Maker();                              // Destructor

  Int_t Init();    // Initiliaze the analysis tools ... done once
  Int_t Make();    // The main analysis that is done on each event
  Int_t Finish();  // Finish the analysis, close files, and clean up.

  void setHistoFileName(TString name) {
    mHistogramOutputFileName = name;
  }  // set the name of output file for histograms
  void setV0TreeFileName(TString name) {
    mV0TreeOutputFileName = name;
  }  // set the name of output file for StV0Dst
  void setV0Type(StV0Type v0type) {
    mV0Type = v0type;
  }  // set the v0 type: kLambda,kAntiLambda,kKs
  void setRotate(bool brot) { mRotate = brot; }  // set rotation option
  void setSameSignPlus(bool brot) {
    mSameSignPlus = brot;
  }  // set same sign plus
  void setSameSignMinus(bool brot) {
    mSameSignMinus = brot;
  }  // set same sign minus

  const StV0Dst& getV0Dst() const { return mV0Dst; }
  bool passEventCut() const { return mPassEventCut; }
  // Rotate dau1 or dau2 tracks by certain degrees in the azimuthal plane with
  // respect to the primary vertex.
  StPhysicalHelixD RotHelix(StPhysicalHelixD Helix, StThreeVectorD Pv,
                            double degree, double magn, int charge);

  int index_for_p(float);

  ClassDef(StV0Maker, 1)  // Macro for CINT compatability
};

#endif
