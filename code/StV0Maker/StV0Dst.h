/**
 ** This file is part of the StV0Maker project.
 ** Copyright 2018 xiaohai <xiaohaijin@outlook.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef StV0Dst_def
#define StV0Dst_def

///
/// \brief MAX_NUM_V0
/// The max multi.
const int MAX_NUM_V0 = 3000;

///
/// \brief The StV0Dst struct
/// V0 and daughter information
struct StV0Dst {
  ///
  /// \brief event infomation.
  ///
  int nrefmult;       ///< nrefmulti
  float primvertexX;  ///< primary vertex X
  float primvertexY;  ///< primary vertex Y
  float primvertexZ;  ///< primary vertex Z
  float vpdVz;        ///< ??
  float magn;         ///< magnetic field
  int nv0;            ///< ???
  long eventid;       ///< event ID
  long runid;         ///< run ID

  ///
  /// \brief The track information
  // StV0Data v0[1000];
  float v0mass[MAX_NUM_V0];      ///< mass
  float v0pt[MAX_NUM_V0];        ///< pt
  float v0rapidity[MAX_NUM_V0];  ///< rapidity
  float v0eta[MAX_NUM_V0];       ///< eta
  float v0x[MAX_NUM_V0];         ///< x
  float v0y[MAX_NUM_V0];         ///< y
  float v0z[MAX_NUM_V0];         ///< z
  float v0px[MAX_NUM_V0];        ///< px
  float v0py[MAX_NUM_V0];        ///< py
  float v0pz[MAX_NUM_V0];        ///< pz
  float v0xpath[MAX_NUM_V0];     ///< xpath ?????
  float v0ypath[MAX_NUM_V0];     ///< ypath ?????
  float v0zpath[MAX_NUM_V0];     ///< zpath ?????
  float v0pxpath[MAX_NUM_V0];    ///< px path ??????
  float v0pypath[MAX_NUM_V0];    ///< py path ??????
  float v0pzpath[MAX_NUM_V0];    ///< pz path ??????
  float v0declen[MAX_NUM_V0];    ///< declen ?????
  float v0declenH[MAX_NUM_V0];   ///< declenH ?????
  float v0dca[MAX_NUM_V0];       ///< dca ??????
  float v0rdotp[MAX_NUM_V0];     ///< rdotp ??????
  float v0sinth[MAX_NUM_V0];     ///< sinth ??????
  float v0theta[MAX_NUM_V0];     ///< theta
  float dca1to2[MAX_NUM_V0];     ///< 1to2 ?????

  ///
  /// \brief The first daughter information
  ///
  int dau1id[MAX_NUM_V0];             ///< ID
  float dau1dca[MAX_NUM_V0];          ///< dca
  float dau1mass[MAX_NUM_V0];         ///< mass
  float dau1eta[MAX_NUM_V0];          ///< eta
  int dau1nhitsfit[MAX_NUM_V0];       ///< nhits fit
  int dau1nhitsdedx[MAX_NUM_V0];      ///< nhits dEdX
  int dau1nhitsposs[MAX_NUM_V0];      ///< nhits poss ??????
  int dau1hftbits[MAX_NUM_V0];        ///< hftbits ???
  float dau1nsigma[MAX_NUM_V0];       ///< sigma
  float dau1pt[MAX_NUM_V0];           ///< pt
  float dau1px[MAX_NUM_V0];           ///< px
  float dau1py[MAX_NUM_V0];           ///< py
  float dau1pz[MAX_NUM_V0];           ///< pz
  float dau1dEdx[MAX_NUM_V0];         ///< dEdX
  float dau1Z[MAX_NUM_V0];            ///< Z
  float dau1beta[MAX_NUM_V0];         ///< beta
  float dau1diffinvbeta[MAX_NUM_V0];  ///< diffinvbeta ?????
  float dau1toflocaly[MAX_NUM_V0];    ///< TOF local y
  float dau1toflocalz[MAX_NUM_V0];    ///< TOF local z
  int dau1PXL1[MAX_NUM_V0];           ///< PXL1 ??????
  int dau1PXL2[MAX_NUM_V0];           ///< PXL2 ??????
  int dau1PXL3[MAX_NUM_V0];           ///< PXL3 ??????
  int dau1IST1[MAX_NUM_V0];           ///< IST1 ??????
  int dau1IST2[MAX_NUM_V0];           ///< IST2 ??????
  int dau1SSD1[MAX_NUM_V0];           ///< SSD1 ??????
  int dau1SSD2[MAX_NUM_V0];           ///< SSD2

  ///
  /// \brief The second daughter information
  ///
  int dau2id[MAX_NUM_V0];             ///< ID
  float dau2dca[MAX_NUM_V0];          ///< dca
  float dau2mass[MAX_NUM_V0];         ///< mass
  float dau2eta[MAX_NUM_V0];          ///< eta
  int dau2nhitsfit[MAX_NUM_V0];       ///< nhits fit
  int dau2nhitsdedx[MAX_NUM_V0];      ///< nhits dEdX
  int dau2nhitsposs[MAX_NUM_V0];      ///< hits poss position ????
  int dau2hftbits[MAX_NUM_V0];        ///< hft bits ??? hits ???
  float dau2nsigma[MAX_NUM_V0];       ///< nsigma ?????
  float dau2pt[MAX_NUM_V0];           ///< pt
  float dau2px[MAX_NUM_V0];           ///< px
  float dau2py[MAX_NUM_V0];           ///< py
  float dau2pz[MAX_NUM_V0];           ///< pz
  float dau2dEdx[MAX_NUM_V0];         ///< dEdX
  float dau2Z[MAX_NUM_V0];            ///< Z ?????
  float dau2beta[MAX_NUM_V0];         ///< beta (v)
  float dau2diffinvbeta[MAX_NUM_V0];  ///< diffinv beta ?????
  float dau2toflocaly[MAX_NUM_V0];    ///< TOF local y
  float dau2toflocalz[MAX_NUM_V0];    ///< TOF local z
  int dau2PXL1[MAX_NUM_V0];           ///< PXL1 ??????
  int dau2PXL2[MAX_NUM_V0];           ///< PXL2 ??????
  int dau2PXL3[MAX_NUM_V0];           ///< PXL3 ??????
  int dau2IST1[MAX_NUM_V0];           ///< IST1 ??????
  int dau2IST2[MAX_NUM_V0];           ///< IST2 ??????
  int dau2SSD1[MAX_NUM_V0];           ///< SSD1 ??????
  int dau2SSD2[MAX_NUM_V0];           ///< SSD2 ??????
};

#endif
