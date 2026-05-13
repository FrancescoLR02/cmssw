//-------------------------------------------------
//
/**  \class L1MuBMTFConfig
 *
 *   Configuration parameters for L1MuBMTrackFinder
 *
 *
 *
 *   N. Neumeister            CERN EP
 */
//
//--------------------------------------------------
#ifndef L1MUBM_TF_CONFIG_H
#define L1MUBM_TF_CONFIG_H

//---------------
// C++ Headers --
//---------------

#include <string>

//----------------------
// Base Class Headers --
//----------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include <FWCore/Utilities/interface/InputTag.h>
#include "CondFormats/L1TObjects/interface/L1TMuonBarrelParams.h"

//              ---------------------
//              -- Class Interface --
//              ---------------------

class L1MuBMTFConfig {
public:
  /// constructor
  explicit L1MuBMTFConfig(const edm::ParameterSet& ps);

  void setDefaultsES(const L1TMuonBarrelParams&);

  edm::InputTag getBMDigiInputTag() const { return m_BMDigiInputTag; }
  edm::InputTag getBMThetaDigiInputTag() const { return m_BMThetaDigiInputTag; }

  bool Debug() const { return m_debug; }
  bool Debug(int level) const { return (m_debug && m_dbgLevel >= level); }

  void setDebugLevel(int level) { m_dbgLevel = level; }
  int getDebugLevel() const { return m_dbgLevel; }

  int getBxMin() const { return m_BxMin; }
  int getBxMax() const { return m_BxMax; }
  int getExtTSFilter() const { return m_extTSFilter; }
  bool getopenLUTs() const { return m_openLUTs; }
  bool getUseEX21() const { return m_useEX21; }
  bool getEtaTF() const { return m_etaTF; }
  bool getTSOutOfTimeFilter() const { return m_TSOutOfTimeFilter; }
  int getTSOutOfTimeWindow() const { return m_TSOutOfTimeWindow; }
  int getNbitsExtPhi() const { return m_NbitsExtPhi; }
  int getNbitsExtPhib() const { return m_NbitsExtPhib; }
  int getNbitsPtaPhi() const { return m_NbitsPtaPhi; }
  int getNbitsPtaPhib() const { return m_NbitsPtaPhib; }
  int getNbitsPhiPhi() const { return m_NbitsPhiPhi; }
  int getNbitsPhiPhib() const { return m_NbitsPhiPhib; }

private:
  void setDefaults(edm::ParameterSet const&);

private:
 static edm::InputTag m_BMDigiInputTag;
  static edm::InputTag m_BMThetaDigiInputTag;

  static int m_dbgLevel;  // debug level

  static int m_BxMin;
  static int m_BxMax;

  static int m_extTSFilter;  // Extrapolation TS-Quality Filter

  static int m_TSOutOfTimeWindow;  // phi window size to be checked

  static int m_NbitsExtPhi;  // precision for extrapolation
  static int m_NbitsExtPhib;
  static int m_NbitsPtaPhi;  // precision for pt-assignment
  static int m_NbitsPtaPhib;
  static int m_NbitsPhiPhi;  // precision for phi-assignment
  static int m_NbitsPhiPhib;

  static bool m_debug;              // debug flag
  static bool m_openLUTs;           // use open LUTs
  static bool m_useEX21;            // perform EX21 extrapolation (cross-check EX12)
  static bool m_etaTF;               // use eta track finder
  static bool m_TSOutOfTimeFilter;  // perform out-of-time TS cancellation
};

#endif
