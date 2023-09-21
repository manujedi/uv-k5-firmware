/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 * /* Copyright 2023 Manuel Jedinger
 * https://github.com/manujedi
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#ifndef BK4819_REGS_H
#define BK4819_REGS_H

enum BK4819_REGISTER_t {
    //! Soft Reset
    /*! 1=Reset; 0=Normal */
    BK4819_REG_00 = 0x00U,
    /*!\<15> FSK Tx Finished Interrupt.\n
    \<14> FSK FIFO Almost Empty Interrupt Enable.\n
    \<13> FSK Rx Finished Interrupt Enable.\n
    \<12> FSK FIFO Almost FullInterrupt.\n
    \<11> DTMF/5TONE Found Interrupt.\n
    \<10> CTCSS/CDCSSTail Found Interrupt.\n
    \<9> CDCSS Found Interrupt.\n
    \<8> CDCSS Lost Interrupt.\n
    \<7> CTCSS Found Interrupt.\n
    \<6> CTCSS Lost Interrupt.\n
    \<5> VoX Found Interrupt.\n
    \<4> VoX Lost Interrupt.\n
    \<3> Squelch Found Interrupt.\n
    \<2> Squelch Lost Interrupt.\n
    \<1> FSK Rx Sync Interrupt.\n */
    BK4819_REG_02 = 0x02U,
    BK4819_REG_06 = 0x06U,
    /*!
     * When \<13>=0 for CTC1 \<12:0>=CTC1 frequencycontrolword
     *   = freq(Hz)*20.64888 for XTAL 13M/26M or
     *   = freq(Hz)*20.97152 for XTAL 12.8M/19.2M/25.6M/38.4M
     *   When<13>=1 for CTC2(Tail 55Hz Rx detection)
     *   \<12:0>=CTC2(should below 100Hz)frequencycontrolword
     *   = 25391/freq(Hz) for XTAL 13M/26M or
     *   = 25000/freq(Hz) for XTAL 12.8M/19.2M/25.6M/38.4M
     *   When \<13>=2 for CDCSS 134.4Hz
     *   \<12:0>=CDCSS baud rate frequency(134.4Hz) controlword
     *   = freq(Hz)*20.64888 for XTAL 13M/26M or
     *   =freq(Hz)*20.97152 for XTAL 12.8M/19.2M/25.6M/38.4M */
    BK4819_REG_07 = 0x07U,
    /*!
    \<15>=1 for CDCSS high 12bit\n
    \<15>=0 for CDCSS low 12bit\n
    \<11:0>=CDCSShigh/low 12bit code\n */
    BK4819_REG_08 = 0x08U,
    /*!
    DTMF/SelCall Symbol Coefficient for Detection.\n
    \<15:12> Symbol Number\n
    \<7:0> Coefficient.\n */
    BK4819_REG_09 = 0x09U,
    /*!
    \<11:8> DTMF/5Tone Code Received.\n
    \<7> FSK Rx SyncNegativehas been Found.\n
    \<6> FSK Rx SyncPositivehas been Found.\n
    \<4> FSK Rx CRC Indicator. 1=CRC Pass; 0=CRC Fail.\n */
    BK4819_REG_0B = 0x0BU,
    /*!
    \<15> CDCSS negative code received.\n
    \<14> CDCSS positive code received.\n
    \<13:12> CTCSS Phase Shift Received.\n
        00 = No phase shift.\n
        01 = CTCSS0 120 °phase shift.\n
        10 = CTCSS0 180 °phase shift.\n
        11 = CTCSS0 240 °phase shift.\n
        \<11>:CTC2(55Hz) received.\n
    \<11> CTC2(55Hz) received\n
    \<10> CTC1 received\n
    \<2> VoXIndicator 0: No 1: Yes\n
    \<1> Squelch resultoutput. 1=Link; 0=Loss\n
    \<0> Interrupt Indicator. 1=Interrupt Request; 0=No Request.\n */
    BK4819_REG_0C = 0x0CU,
    /*!
    \<15> Frequency Scan Indicator. 1=Busy; 0=Finished.\n
    \<10:0> Frequency Scan High 16 bits\n */
    BK4819_REG_0D = 0x0DU,
    /*!
    \<15:0> Frequency Scan Low 16 bits.\n
    \= REG_0D\<10:0>\<\<16 + REG_0E\<15:0>, unit is 10Hz\n */
    BK4819_REG_0E = 0x0EU,
    /*!
    \<15:0> 0x0038 Rx AGC Gain Table[0]. (Index Max->Min is 3,2,1,0,-1)\n
    \<9:8>=LNA Gain Short 11=0dB; 10=-11dB; 01=-16dB; 00=-19dB.\n
    \<7:5>=LNA Gain 111=0dB; 110=-2dB; 101=-4dB; 100=-6dB; 011=-9dB; 010=-14dB; 001=-19dB; 000=-24dB.\n
    \<4:3>=MIXER Gain 11=0dB; 10=-3dB; 01=-6dB; 00=-8dB.\n
    \<2:0>=PGA Gain 111=0dB; 110=-3dB; 101=-6dB; 100=-9dB; 011=-15dB; 010=-21dB; 001=-27dB; 000=-33dB. */
    BK4819_REG_10 = 0x10U,
    /*!
    \<15:0> Rx AGC Gain Table[1]. (Index Max->Min is 3,2,1,0,-1)\n
    \<9:8>=LNA Gain Short 11=0dB; 10=-11dB; 01=-16dB; 00=-19dB.\n
    \<7:5>=LNA Gain 111=0dB; 110=-2dB; 101=-4dB; 100=-6dB; 011=-9dB; 010=-14dB; 001=-19dB; 000=-24dB.\n
    \<4:3>=MIXER Gain 11=0dB; 10=-3dB; 01=-6dB; 00=-8dB.\n
    \<2:0>=PGA Gain 111=0dB; 110=-3dB; 101=-6dB; 100=-9dB; 011=-15dB; 010=-21dB; 001=-27dB; 000=-33dB. */
    BK4819_REG_11 = 0x11U,
    /*!
    \<15:0> Rx AGC Gain Table[2]. (Index Max->Min is 3,2,1,0,-1)\n
    \<9:8>=LNA Gain Short 11=0dB; 10=-11dB; 01=-16dB; 00=-19dB.\n
    \<7:5>=LNA Gain 111=0dB; 110=-2dB; 101=-4dB; 100=-6dB; 011=-9dB; 010=-14dB; 001=-19dB; 000=-24dB.\n
    \<4:3>=MIXER Gain 11=0dB; 10=-3dB; 01=-6dB; 00=-8dB.\n
    \<2:0>=PGA Gain 111=0dB; 110=-3dB; 101=-6dB; 100=-9dB; 011=-15dB; 010=-21dB; 001=-27dB; 000=-33dB. */
    BK4819_REG_12 = 0x12U,
    /*!
    \<15:0> Rx AGC Gain Table[3]. (Index Max->Min is 3,2,1,0,-1)\n
    \<9:8>=LNA Gain Short 11=0dB; 10=-11dB; 01=-16dB; 00=-19dB.\n
    \<7:5>=LNA Gain 111=0dB; 110=-2dB; 101=-4dB; 100=-6dB; 011=-9dB; 010=-14dB; 001=-19dB; 000=-24dB.\n
    \<4:3>=MIXER Gain 11=0dB; 10=-3dB; 01=-6dB; 00=-8dB.\n
    \<2:0>=PGA Gain 111=0dB; 110=-3dB; 101=-6dB; 100=-9dB; 011=-15dB; 010=-21dB; 001=-27dB; 000=-33dB. */
    BK4819_REG_13 = 0x13U,
    /*!
    \<15:0> Rx AGC Gain Table[4]. (Index Max->Min is 3,2,1,0,-1)\n
    \<9:8>=LNA Gain Short 11=0dB; 10=-11dB; 01=-16dB; 00=-19dB.\n
    \<7:5>=LNA Gain 111=0dB; 110=-2dB; 101=-4dB; 100=-6dB; 011=-9dB; 010=-14dB; 001=-19dB; 000=-24dB.\n
    \<4:3>=MIXER Gain 11=0dB; 10=-3dB; 01=-6dB; 00=-8dB.\n
    \<2:0>=PGA Gain 111=0dB; 110=-3dB; 101=-6dB; 100=-9dB; 011=-15dB; 010=-21dB; 001=-27dB; 000=-33dB. */
    BK4819_REG_14 = 0x14U,
    /*!
    \<15> Automatic MIC PGA Gain Controller (MIC AGC) Disable. 1=Disable; 0=Enable.*/
    BK4819_REG_19 = 0x19U,
    /*!
    \<15:12> Crystal vReg Bit.\n
    \<11:8> Crystal iBit.*/
    BK4819_REG_1A = 0x1AU,
    /*!
    \<3:0> PLL CP bit*/
    BK4819_REG_1F = 0x1FU,
    BK4819_REG_20 = 0x20U,
    BK4819_REG_21 = 0x21U,
    /*!
    \<5> DTMF/SelCall Enable. 1=Enable; 0=Disable.\n
    \<4> DTMF or SelCall Detection Mode. 1=for DTMF; 0=for SelCall.\n
    \<3:0> Max Symbol Number for SelCall Detection.*/
    BK4819_REG_24 = 0x24U,
    /*!
    \<15:14> Expander (AF Rx) Ratio. 00=Disable; 01=1:2; 10=1:3; 11=1:4\n
    \<13:7> Expander (AF Rx) 0 dB point(dB)\n
    \<6:0> Expander (AF Rx) noise point(dB)*/
    BK4819_REG_28 = 0x28U,
    /*!
    \<15:14> Compress (AF Tx) Ratio. 00=Disable; 01=1.333:1; 10=2:1; 11=4:1\n
    \<13:7> Compress (AF Tx) 0 dB point(dB)\n
    \<6:0> Compress (AF Tx) noise point(dB)*/
    BK4819_REG_29 = 0x29U,
    /*!
    \<10> Disable AFRxHPF300filter. 0=Enable; 1=Disable\n
    \<9> Disable AF RxLPF3K filter. 0=Enable; 1=Disable\n
    \<8> Disable AF Rx de-emphasisfilter. 0=Enable; 1=Disable\n
    \<2> Disable AFTxHPF300filter. 0=Enable; 1=Disable\n
    \<1> Disable AFTxLPF1filter. 0=Enable; 1=Disable\n
    \<0> Disable AFTxpre-emphasisfilter. 0=Enable; 1=Disable
     */
    BK4819_REG_2B = 0x2BU,
    /*!
    \<9:8> CTCSS/CDCSS Tx Gain2 Tuning (after Gain1). 00=12dB; 01=6dB; 10=0dB; 11=-6dB*/
    BK4819_REG_2E = 0x2EU,
    /*!
    \<15> VCO Calibration Enable. 1=Enable, 0=Disable\n
    \<13:10> Rx Link Enable (include LNA/MIXER/PGA/ADC). 1111=Enable, 0000=Disable\n
    \<9> AF DAC Enable. 1=Enable, 0=Disable.\n
    \<8> DISC Mode Disable. 1=Disable, 0=Enable.\n
    \<7:4> PLL/VCO Enable. 1111=Enable, 0000=Disable\n
    \<3> PA Gain Enable. 1=Enable, 0=Disable\n
    \<2> MIC ADC Enable. 1=Enable, 0=Disable\n
    \<1> Tx DSP Enable. 1=Enable, 0=Disable\n
    \<0> Rx DSP Enable. 1=Enable, 0=Disable.*/
    BK4819_REG_30 = 0x30U,
    /*!
    \<3> Enable Compander Function. 1=Enable, 0=Disable\n
    \<2> Enable VOX detection. 1=Enable, 0=Disable\n
    \<1> Enable Scramble Function. 1=Enable, 0=Disable*/
    BK4819_REG_31 = 0x31U,
    /*!
    \<15:14> FrequencyScan Time. 00=0.2 Sec; 01=0.4 Sec; 10=0.8 Sec; 11=1.6 Sec\n
    \<0> FrequencyScanEnable. 1=Enable; 0=Disable. */
    BK4819_REG_32 = 0x32U,
    /*!
    \<15:8> GPIOs Output Disable. 1=Output Disable; 0=Output Enable\n
    \<7:0> GPIOs Output Value. 1= High when Output Enable; 0=Low when Output Enable */
    BK4819_REG_33 = 0x33U,
    /*!
    \<15:12> GPIO4 Output Type Selection\n
    \<11:8> GPIO5 Output Type Selection\n
    \<3:0> GPIO6 Output Type Selection\n
        0=High/Low\n
        1=Interrupt\n
        2=Squelch\n
        3=VoX\n
        4=CTCSS/CDCSS Compared Result\n
        5=CTCSS Compared Result\n
        6=CDCSS Compared Result\n
        7=Tail Detected Result\n
        8=DTMF/5Tone Symbol Received Flag\n
        9=CTCSS/CDCSS Digital Wave\n
        Others=Reserved\n*/
    BK4819_REG_34 = 0x34U,
    /*!
    \<15:12> GPIO0 Output Type Selection\n
    \<11:8> GPIO1 Output Type Selection\n
    \<3:0> GPIO2 Output Type Selection\n
        0=High/Low\n
        1=Interrupt\n
        2=Squelch\n
        3=VoX\n
        4=CTCSS/CDCSS Compared Result\n
        5=CTCSS Compared Result\n
        6=CDCSS Compared Result\n
        7=Tail Detected Result\n
        8=DTMF/5Tone Symbol Received Flag\n
        9=CTCSS/CDCSS Digital Wave\n
        Others=Reserved\n*/
    BK4819_REG_35 = 0x35U,
    /*!
    \<15:8> PA Biasoutput 0~3.2V 0x00=0V…0xFF=3.2V\n
    \<7> 1=Enable PACTLoutput; 0=Disable(Output 0 V)\n
    \<5:3> PA Gain1 Tuning. 111(max)->000(min)\n
    \<2:0> PA Gain2 Tuning. 111(max)->000(min)*/
    BK4819_REG_36 = 0x36U,
    /*!
    \<14:12> DSP Voltage Setting.\n
    \<11> ANA LDO Selection. 1=2.7v, 0=2.4v\n
    \<10> VCO LDO Selection. 1=2.7v, 0=2.4v\n
    \<9> RF LDO Selection. 1=2.7v, 0=2.4v\n
    \<8> PLL LDO Selection. 1=2.7v, 0=2.4v\n
    \<7> ANA LDO Bypass. 1=Bypass, 0=Enable.\n
    \<6> VCO LDO Bypass. 1=Bypass, 0=Enable.\n
    \<5> RF LDO Bypass. 1=Bypass, 0=Enable.\n
    \<4> PLL LDO Bypass. 1=Bypass, 0=Enable.\n
    \<3> Reserved.\n
    \<2> DSP Enable. 1=Enable, 0=Disable.\n
    \<1> XTAL Enable. 1=Enable, 0=Disable.\n
    \<0> Band-Gap Enable. 1=Enable, 0=Disable.*/
    BK4819_REG_37 = 0x37U,
    /*!
    \<15:0> Frequency(Hz)= (freq_hi16\<\<16 + freq_lo16)*10*/
    BK4819_REG_38 = 0x38U,
    BK4819_REG_39 = 0x39U,
    BK4819_REG_3A = 0x3AU,
    /*!
    \<15:0> Crystal Frequency Low-16bits. LSB->5Hz*/
    BK4819_REG_3B = 0x3BU,
    /*!
    \<15:8> Crystal Frequency High-8bits.\n
    \<7:6> Crystal Frequency Mode Selection. 00~=13MHz; 01~=19.2MHz; 10~=26MHz; 11~=38.4MHz*/
    BK4819_REG_3C = 0x3CU,
    /*!
    \<15:0> IF Selection.\n
    0=Zero IF;\n
    0x2aab~=8.46kHz IF;\n
    0x4924~=7.25kHz IF;\n
    0x6800~=6.35kHz IF;\n
    0x871c~=5.64kHz IF;\n
    0xa666~=5.08kHz IF;\n
    0xc5d1~=4.62kHz IF;\n
    0xe555~=4.23kHz IF;\n
    if REG_43<5>=1, IF *=2;*/
    BK4819_REG_3D = 0x3DU,
    /*!
    \<15:0> Band Selection Threshold. ~=VCO Max Frequency(Hz)/96/640*/
    BK4819_REG_3E = 0x3EU,
    /*!
    \<15> FSK Tx Finished Interrupt Enable. 1=Enable; 0=Disable.\n
    \<14> FSK FIFO Almost Empty Interrupt Enable. 1=Enable; 0=Disable.\n
    \<13> FSK Rx Finished Interrupt Enable. 1=Enable; 0=Disable.\n
    \<12> FSK FIFO Almost FullInterrupt Enable. 1=Enable; 0=Disable.\n
    \<11> DTMF/5TONE Found Interrupt Enable. 1=Enable; 0=Disable.\n
    \<10> CTCSS/CDCSSTail Found InterruptEnable. 1=Enable; 0=Disable.\n
    \<9> CDCSS Found InterruptEnable. 1=Enable; 0=Disable.\n
    \<8> CDCSS Lost InterruptEnable. 1=Enable; 0=Disable.\n
    \<7> CTCSS Found InterruptEnable. 1=Enable; 0=Disable.\n
    \<6> CTCSS Lost InterruptEnable. 1=Enable; 0=Disable.\n
    \<5> VoX Found InterruptEnable. 1=Enable; 0=Disable.\n
    \<4> VoX Lost InterruptEnable. 1=Enable; 0=Disable.\n
    \<3> Squelch Found InterruptEnable. 1=Enable; 0=Disable.\n
    \<2> Squelch Lost InterruptEnable. 1=Enable; 0=Disable.\n
    \<1> FSK Rx Sync Interrupt Enable. 1=Enable; 0=Disable.*/
    BK4819_REG_3F = 0x3FU,
    /*!
    \<12> Enable RF TxDeviation. 1=Enable; 0=Disable\n
    \<11:0> RF Tx Deviation Tuning (Apply for both in-band signal and sub-audio signal). 0=min; 0xFFF=max*/
    BK4819_REG_40 = 0x40U,
    /*!
    \<14:12> RF filter bandwidth (Apass=0.1dB)\n
    000 = 1.7 kHz; 001 = 2 kHz; 010 = 2.5 kHz; 011 = 3 kHz; 100 = 3.75 kHz; 101 = 4 kHz; 110 = 4.25 kHz; 111 = 4.5 kHz; if REG_43<5>=1, RF filter bandwidth *=2;\n
    \<11:9> RF filter bandwidth when signal is weak (Apass=0.1dB)
    000 = 1.7 kHz; 001 = 2 kHz; 010 = 2.5 kHz; 011 = 3 kHz; 100 = 3.75 kHz; 101 = 4 kHz; 110 = 4.25 kHz; 111 = 4.5 kHz; if REG_43<5>=1, RF filter bandwidth *=2;\n
    \<8:6> AFTxLPF2 filter Band Width (Apass=1dB) Selection.
    100 = 4.5 kHz; 101 = 4.25 kHz; 110 =4kHz; 111 = 3.75 kHz; 000 = 3 kHz (for 25k Channel Space); 001 = 2.5 kHz (for 12.5k Channel Space); 010 = 2.75 kHz; 011 =3.5 kHz;\n
    \<5:4> BW Mode Selection.\n
    00=12.5k; 01=6.25k; 10=25k/20k\n
    \<2> Gain after FM Demodulation.\n
    1=6dB; 0=0 dB. */
    BK4819_REG_43 = 0x43U,
    /*!
    \<15:0> 300Hz AF Response coefficient for Tx. */
    BK4819_REG_44 = 0x44U,
    /*!
    \<15:0> 300Hz AF Response coefficient for Tx. */
    BK4819_REG_45 = 0x45U,
    /*!
    \<10:0> Voice AmplitudeThreshold for VOX=1 detect. */
    BK4819_REG_46 = 0x46U,
    /*!
    \<13> AF Output Inverse Mode. 1=Inverse.\n
    \<11:8> AFOutputSelection.\n
    0x0=Mute;\n
    0x1=Normal AF Out;\n
    0x2=Tone Out for Rx (Should enable Tone1 first);\n
    0x3=Beep Out for Tx (Should enable Tone1 first and set REG_03[9]=1 to enable AF;\n
    0x6=CTCSS/CDCSS Out for Rx Test;\n
    0x8=FSK Out for Rx Test;\n
    Others=Reserved;\n
    \<0> AF Tx Filter Bypass All. 1=Bypass All AF Tx filter; 0=Normal.*/
    BK4819_REG_47 = 0x47U,
    /*!
    \<11:10> AF Rx Gain1.\n
    00=0dB;01=-6dB;10=-12dB;11=-18dB\n
    \<9:4> AF Rx Gain2.\n
    -26dB~5.5dB, 0.5dB/step. 0x00=mute\n
    \<3:0> AF DAC Gain (after Gain1 and Gain2).\n
    1111=max; 0000=min; about 2dB/step*/
    BK4819_REG_48 = 0x48U,
    BK4819_REG_49 = 0x49U,
    /*!
    \<5> AF Level Controller(ALC) Disable. 1=Disable; 0=Enable.*/
    BK4819_REG_4B = 0x4BU,
    /*!
    \<7:0> Glitch threshold for Squelch =0*/
    BK4819_REG_4D = 0x4DU,
    /*!
    \<13:11> Squelch=1 Delay Setting.\n
    \<10:9> Squelch=0 Delay Setting.\n
    \<7:0> Glitch threshold for Squelch =1*/
    BK4819_REG_4E = 0x4EU,
    /*!
    \<14:8> Ex-noise threshold for Squelch =0\n
    \<6:0> Ex-noise threshold for Squelch =1*/
    BK4819_REG_4F = 0x4FU,
    /*!
    \<15> Enable AF Tx Mute (for DTMF Tx or other applications). 1=Mute; 0=Normal*/
    BK4819_REG_50 = 0x50U,
    /*!
    \<15> 1=Enable TxCTCSS/CDCSS; 0=Disable\n
    \<14> 1= GPIO0Input for CDCSS; 0=Normal Mode.(for BK4819v3)\n
    \<13> 1=Transmit negative CDCSS code. 0=Transmit positive CDCSScode\n
    \<12> CTCSS/CDCSS mode selection. 1=CTCSS, 0=CDCSS\n
    \<11> CDCSS 24/23bit selection. 1=24bit, 0=23bit\n
    \<10> 1050HzDetectionMode. 1=1050/4 Detect Enable, CTC1 should be set to 1050/4 Hz\n
    \<9> Auto CDCSS Bw Mode. 1=Disable; 0=Enable.\n
    \<8> Auto CTCSS Bw Mode. 0=Enable; 1=Disable\n
    \<6:0> CTCSS/CDCSS Tx Gain1 Tuning. 0=min; 0x7F=max*/
    BK4819_REG_51 = 0x51U,
    /*!
    \<15> Enable 120/180/240 degree shift CTCSS or 134.4Hz Tail when CDCSS mode. 0=Normal, 1=Enable\n
    \<14:13> CTCSS tail modeselection (only valid when REG_52<15>=1).\n
    00= for 134.4Hz CTCSS Tail when CDCSS mode.\n
    01=CTCSS0 120° phase shift,\n
    10= CTCSS0 180° phase shift\n
    11= CTCSS0 240° phase shift\n
    \<12> CTCSSDetectionThreshold Mode, 1=~0.1%; 0=0.1 Hz\n
    \<11:6> CTCSS found detect threshold.\n
    \<5:0> CTCSS lost detect threshold.*/
    BK4819_REG_52 = 0x52U,
    /*!
    \<15:0> 300Hz AF Response coefficient for Rx.*/
    BK4819_REG_54 = 0x54U,
    /*!
    \<15:0> 300Hz AF Response coefficient for Rx.*/
    BK4819_REG_55 = 0x55U,
    /*!
    \<15:13> FSK Tx Mode Selection.\n
    000 for FSK1.2K and FSK2.4K Tx;\n
    001 for FFSK1200/1800 Tx;\n
    011 for FFSK1200/2400 Tx;\n
    101 for NOAA SAME Tx;\n
    \<12:10> FSK Rx Mode Selection.\n
    000 for FSK1.2K, FSK2.4K Rx and NOAA SAME Rx;\n
    111 for FFSK1200/1800 Rx;\n
    100 for FFSK1200/2400 Rx;\n
    \<9:8> FSK Rx Gain.\n
    \<5:4> FSK Preamble Type Selection.\n
    11=0xAA; \n
    10=0x55; \n
    00=0xAA or 0x55 due to the MSB of FSK Sync Byte 0.\n
    \<3:1>FSK Rx BandWidth Setting.\n
    100 for FSK 2.4K and FFSK1200/2400;\n
    000 for FSK 1.2K;\n
    001 for FFSK1200/1800;\n
    010 for NOAA SAME Rx\n
    \<0>FSK Enable. 1=Enable; 0=Disable.\n
    */
    BK4819_REG_58 = 0x58U,
    /*!
    \<15> Clear TX FIFO, 1=clear\n
    \<14> Clear RX FIFO, 1=clear\n
    \<13> 1=Enable FSK Scramble\n
    \<12> 1=Enable FSK RX\n
    \<11> 1=Enable FSK TX\n
    \<10> 1=Invert FSK data when RX\n
    \<9> 1=Invert FSK data when TX\n
    \<7:4> FSK Preamble Length Selection\n
    0=1 byte; 1=2 bytes; 2=3 bytes; …; 15=16 bytes\n
    \<3> FSK SyncLength Selection.\n
    1=4 bytes (FSK Sync Byte 0,1,2,3); 0=2 bytes (FSK Sync Byte 0,1)*/
    BK4819_REG_59 = 0x59U,
    /*!
    \<15:8> FSK Sync Byte 0 (Sync Byte 0 first, then 1,2,3)\n
    \<7:0> FSK Sync Byte 1*/
    BK4819_REG_5A = 0x5AU,
    /*!
    \<15:8> FSK Sync Byte 2\n
    \<7:0> FSK Sync Byte 3*/
    BK4819_REG_5B = 0x5BU,
    /*!
    \<6> CRC Option Enable. 1=Enable; 0=Disable.*/
    BK4819_REG_5C = 0x5CU,
    /*!
    \<15:8> FSK Data Length(Byte)Low 8bits(Total 11 bits for BK4819v3). For example, 0xF means 16 bytes length\n
    \<7:0> FSK Data Length(Byte)High 3bits(Total 11 bits for BK4819v3).*/
    BK4819_REG_5D = 0x5DU,
    /*!
    \<9:3> FSK Tx FIFO (Total 128 Words) Almost Empty Threshold.\n
    \<2:0> FSK Rx FIFO (Total 8 Words) Almost Full Threshold.*/
    BK4819_REG_5E = 0x5EU,
    /*!
    \<15:0> FSK Word Input/Output. */
    BK4819_REG_5F = 0x5FU,
    /*!
    \<7:0> Glitch indicator. */
    BK4819_REG_63 = 0x63U,
    /*!
    \<15:0> Voice AmplitudeOut. */
    BK4819_REG_64 = 0x64U,
    /*!
    \<6:0> Ex-noiseindicator, dB/step. */
    BK4819_REG_65 = 0x65U,
    /*!
    \<8:0> 0.5dB/step, RSSI (dBm) ~= REG_67<8:0>/2 – 160. */
    BK4819_REG_67 = 0x67U,
    /*!
    \<15> CTCSS Scan Indicator. 1=Busy; 0=Found.\n
    \<12:0> CTCSS Frequency.\n
    Frequency(Hz)\n
    = REG_68<12:0>/20.64888 for 13M/26M XTAL and\n
    = REG_68<12:0>/20.97152 for 12.8M/19.2M/25.6M/38.4M XTAL*/
    BK4819_REG_68 = 0x68U,
    /*!
    \<15> CTCSS Scan Indicator. 1=Busy; 0=Found.\n
    \<14> 23 or 24 bit CDCSS Indicator.(for BK4819v3) 1=24 bit; 0=23 bit.\n
    \<11:0> CDCSS High 12 bits.*/
    BK4819_REG_69 = 0x69U,
    /*!
    \<11:0> CDCSS Low 12 bits.*/
    BK4819_REG_6A = 0x6AU,
    /*!
    \<6:0> AF Tx/Rx Input Amplitude(dB)*/
    BK4819_REG_6F = 0x6FU,
    /*!
    \<15> Enable TONE1 1=Enable; 0=Disable.\n
    \<14:8> TONE1tuninggain \n
    \<7> Enable TONE2. 1=Enable; 0=Disable.\n
    \<6:0> TONE2/FSK tuninggain*/
    BK4819_REG_70 = 0x70U,
    /*!
    \<15:0> TONE1/Scramblefrequencycontrolword. =freq(Hz)*10.32444 for XTAL 13M/26M or\n
     =freq(Hz)* 10.48576 for XTAL 12.8M/19.2M/25.6M*/
    BK4819_REG_71 = 0x71U,
    /*!
    \<15:0> TONE2/FSK frequencycontrolword =freq(Hz)*10.32444 for XTAL 13M/26M or\n
    =freq(Hz)* 10.48576 for XTAL 12.8M/19.2M/25.6M/38.4M.*/
    BK4819_REG_72 = 0x72U,
    /*!
    \<13:11> Automatic Frequency Correction(AFC) Range Selection. 000=max; 111=min\n
    \<4> Automatic Frequency Correction(AFC) Disable. 1=Disable; 0=Enable.*/
    BK4819_REG_73 = 0x73U,
    /*!
    \<15:0> 3000Hz AF Response coefficient for Tx.*/
    BK4819_REG_74 = 0x74U,
    /*!
    \<15:0> 3000Hz AF Response coefficient for Rx.*/
    BK4819_REG_75 = 0x75U,
    /*!
    \<15:8> RSSI threshold for Squelch=1, 0.5dB/step\n
    \<7:0> RSSI threshold for Squelch =0, 0.5dB/step*/
    BK4819_REG_78 = 0x78U,
    /*!
    \<15:11> VoX Detection Interval Time.\n
    \<7:0> Voice Amplitude Threshold for VOX=0 detect*/
    BK4819_REG_79 = 0x79U,
    /*!
    \<4:0> VoX=0 Detection delay, *128ms*/
    BK4819_REG_7A = 0x7AU,
    BK4819_REG_7B = 0x7BU,
    BK4819_REG_7C = 0x7CU,
    /*!
    \<4:0> MIC Sensitivity Tuning. 0x00=min; 0x1F=max; 0.5dB/step*/
    BK4819_REG_7D = 0x7DU,
    /*!
    \<15> AGC Fix Mode. 1=Fix; 0=Auto.\n
    \<14:12> AGC Fix Index. 011=Max, then 010,001,000,111,110,101,100(min).\n
    \<5:3> DC Filter Band Width for Tx (MIC In). 000=Bypass DC filter;\n
    \<2:0> DC Filter Band Width for Rx (IF In). 000=Bypass DC filter;*/
    BK4819_REG_7E = 0x7EU,
};

typedef enum BK4819_REGISTER_t BK4819_REGISTER_t;

enum BK4819_GPIO_PIN_t {
	BK4819_GPIO6_PIN2 = 0,
	BK4819_GPIO5_PIN1 = 1,
	BK4819_GPIO4_PIN32 = 2,
	BK4819_GPIO3_PIN31 = 3,
	BK4819_GPIO2_PIN30 = 4,
	BK4819_GPIO1_PIN29_RED = 5,
	BK4819_GPIO0_PIN28_GREEN = 6,
};

typedef enum BK4819_GPIO_PIN_t BK4819_GPIO_PIN_t;

// REG 02

#define BK4819_REG_02_SHIFT_FSK_TX_FINISHED		15
#define BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_EMPTY	14
#define BK4819_REG_02_SHIFT_FSK_RX_FINISHED		13
#define BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_FULL	12
#define BK4819_REG_02_SHIFT_DTMF_5TONE_FOUND		11
#define BK4819_REG_02_SHIFT_CxCSS_TAIL			10
#define BK4819_REG_02_SHIFT_CDCSS_FOUND			9
#define BK4819_REG_02_SHIFT_CDCSS_LOST			8
#define BK4819_REG_02_SHIFT_CTCSS_FOUND			7
#define BK4819_REG_02_SHIFT_CTCSS_LOST			6
#define BK4819_REG_02_SHIFT_VOX_FOUND			5
#define BK4819_REG_02_SHIFT_VOX_LOST			4
#define BK4819_REG_02_SHIFT_SQUELCH_FOUND		3
#define BK4819_REG_02_SHIFT_SQUELCH_LOST		2
#define BK4819_REG_02_SHIFT_FSK_RX_SYNC			1

#define BK4819_REG_02_MASK_FSK_TX_FINISHED		(1U << BK4819_REG_02_SHIFT_FSK_TX)
#define BK4819_REG_02_MASK_FSK_FIFO_ALMOST_EMPTY	(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_02_MASK_FSK_RX_FINISHED		(1U << BK4819_REG_02_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_02_MASK_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_02_MASK_DTMF_5TONE_FOUND		(1U << BK4819_REG_02_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_02_MASK_CxCSS_TAIL			(1U << BK4819_REG_02_SHIFT_CxCSS_TAIL)
#define BK4819_REG_02_MASK_CDCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CDCSS_FOUND)
#define BK4819_REG_02_MASK_CDCSS_LOST			(1U << BK4819_REG_02_SHIFT_CDCSS_LOST)
#define BK4819_REG_02_MASK_CTCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CTCSS_FOUND)
#define BK4819_REG_02_MASK_CTCSS_LOST			(1U << BK4819_REG_02_SHIFT_CTCSS_LOST)
#define BK4819_REG_02_MASK_VOX_FOUND			(1U << BK4819_REG_02_SHIFT_VOX_FOUND)
#define BK4819_REG_02_MASK_VOX_LOST			(1U << BK4819_REG_02_SHIFT_VOX_LOST)
#define BK4819_REG_02_MASK_SQUELCH_FOUND		(1U << BK4819_REG_02_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_02_MASK_SQUELCH_LOST			(1U << BK4819_REG_02_SHIFT_SQUELCH_LOST)
#define BK4819_REG_02_MASK_FSK_RX_SYNC			(1U << BK4819_REG_02_SHIFT_FSK_RX_SYNC)

#define BK4819_REG_02_FSK_TX_FINISHED			(1U << BK4819_REG_02_SHIFT_FSK_TX_FINISHED)
#define BK4819_REG_02_FSK_FIFO_ALMOST_EMPTY		(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_02_FSK_RX_FINISHED			(1U << BK4819_REG_02_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_02_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_02_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_02_DTMF_5TONE_FOUND			(1U << BK4819_REG_02_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_02_CxCSS_TAIL			(1U << BK4819_REG_02_SHIFT_CxCSS_TAIL)
#define BK4819_REG_02_CDCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CDCSS_FOUND)
#define BK4819_REG_02_CDCSS_LOST			(1U << BK4819_REG_02_SHIFT_CDCSS_LOST)
#define BK4819_REG_02_CTCSS_FOUND			(1U << BK4819_REG_02_SHIFT_CTCSS_FOUND)
#define BK4819_REG_02_CTCSS_LOST			(1U << BK4819_REG_02_SHIFT_CTCSS_LOST)
#define BK4819_REG_02_VOX_FOUND				(1U << BK4819_REG_02_SHIFT_VOX_FOUND)
#define BK4819_REG_02_VOX_LOST				(1U << BK4819_REG_02_SHIFT_VOX_LOST)
#define BK4819_REG_02_SQUELCH_FOUND			(1U << BK4819_REG_02_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_02_SQUELCH_LOST			(1U << BK4819_REG_02_SHIFT_SQUELCH_LOST)
#define BK4819_REG_02_FSK_RX_SYNC			(1U << BK4819_REG_02_SHIFT_FSK_RX_SYNC)

// REG 07

#define BK4819_REG_07_SHIFT_FREQUENCY_MODE	13
#define BK4819_REG_07_SHIFT_FREQUENCY		0

#define BK4819_REG_07_MASK_FREQUENCY_MODE	(0x0007U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)
#define BK4819_REG_07_MASK_FREQUENCY		(0x1FFFU << BK4819_REG_07_SHIFT_FREQUENCY)

#define BK4819_REG_07_MODE_CTC1			(0U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)
#define BK4819_REG_07_MODE_CTC2			(1U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)
#define BK4819_REG_07_MODE_CDCSS		(2U << BK4819_REG_07_SHIFT_FREQUENCY_MODE)

// REG 24

#define BK4819_REG_24_SHIFT_UNKNOWN_15		15
#define BK4819_REG_24_SHIFT_THRESHOLD		7
#define BK4819_REG_24_SHIFT_UNKNOWN_6		6
#define BK4819_REG_24_SHIFT_ENABLE		5
#define BK4819_REG_24_SHIFT_SELECT		4
#define BK4819_REG_24_SHIFT_MAX_SYMBOLS		0

#define BK4819_REG_24_MASK_THRESHOLD		(0x2FU << BK4819_REG_24_SHIFT_THRESHOLD)
#define BK4819_REG_24_MASK_ENABLE		(0x01U << BK4819_REG_24_SHIFT_ENABLE)
#define BK4819_REG_24_MASK_SELECT		(0x04U << BK4819_REG_24_SHIFT_SELECT)
#define BK4819_REG_24_MASK_MAX_SYMBOLS		(0x0FU << BK4819_REG_24_SHIFT_MAX_SYMBOLS)

#define BK4819_REG_24_ENABLE			(0x01U << BK4819_REG_24_SHIFT_ENABLE)
#define BK4819_REG_24_DISABLE			(0x00U << BK4819_REG_24_SHIFT_ENABLE)
#define BK4819_REG_24_SELECT_DTMF		(0x01U << BK4819_REG_24_SHIFT_SELECT)
#define BK4819_REG_24_SELECT_SELCALL		(0x00U << BK4819_REG_24_SHIFT_SELECT)

// REG 30

#define BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB	15
#define BK4819_REG_30_SHIFT_ENABLE_UNKNOWN	14
#define BK4819_REG_30_SHIFT_ENABLE_RX_LINK	10
#define BK4819_REG_30_SHIFT_ENABLE_AF_DAC	9
#define BK4819_REG_30_SHIFT_ENABLE_DISC_MODE	8
#define BK4819_REG_30_SHIFT_ENABLE_PLL_VCO	4
#define BK4819_REG_30_SHIFT_ENABLE_PA_GAIN	3
#define BK4819_REG_30_SHIFT_ENABLE_MIC_ADC	2
#define BK4819_REG_30_SHIFT_ENABLE_TX_DSP	1
#define BK4819_REG_30_SHIFT_ENABLE_RX_DSP	0

#define BK4819_REG_30_MASK_ENABLE_VCO_CALIB	(0x1U << BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB)
#define BK4819_REG_30_MASK_ENABLE_UNKNOWN	(0x1U << BK4819_REG_30_SHIFT_ENABLE_UNKNOWN)
#define BK4819_REG_30_MASK_ENABLE_RX_LINK	(0xFU << BK4819_REG_30_SHIFT_ENABLE_RX_LINK)
#define BK4819_REG_30_MASK_ENABLE_AF_DAC	(0x1U << BK4819_REG_30_SHIFT_ENABLE_AF_DAC)
#define BK4819_REG_30_MASK_ENABLE_DISC_MODE	(0x1U << BK4819_REG_30_SHIFT_ENABLE_DISC_MODE)
#define BK4819_REG_30_MASK_ENABLE_PLL_VCO	(0xFU << BK4819_REG_30_SHIFT_ENABLE_PLL_VCO)
#define BK4819_REG_30_MASK_ENABLE_PA_GAIN	(0x1U << BK4819_REG_30_SHIFT_ENABLE_PA_GAIN)
#define BK4819_REG_30_MASK_ENABLE_MIC_ADC	(0x1U << BK4819_REG_30_SHIFT_ENABLE_MIC_ADC)
#define BK4819_REG_30_MASK_ENABLE_TX_DSP	(0x1U << BK4819_REG_30_SHIFT_ENABLE_TX_DSP)
#define BK4819_REG_30_MASK_ENABLE_RX_DSP	(0x1U << BK4819_REG_30_SHIFT_ENABLE_RX_DSP)

enum {
	BK4819_REG_30_ENABLE_VCO_CALIB		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB),
	BK4819_REG_30_DISABLE_VCO_CALIB		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_VCO_CALIB),
	BK4819_REG_30_ENABLE_UNKNOWN		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_UNKNOWN),
	BK4819_REG_30_DISABLE_UNKNOWN		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_UNKNOWN),
	BK4819_REG_30_ENABLE_RX_LINK		= (0xFU << BK4819_REG_30_SHIFT_ENABLE_RX_LINK),
	BK4819_REG_30_DISABLE_RX_LINK		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_RX_LINK),
	BK4819_REG_30_ENABLE_AF_DAC		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_AF_DAC),
	BK4819_REG_30_DISABLE_AF_DAC		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_AF_DAC),
	BK4819_REG_30_ENABLE_DISC_MODE		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_DISC_MODE),
	BK4819_REG_30_DISABLE_DISC_MODE		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_DISC_MODE),
	BK4819_REG_30_ENABLE_PLL_VCO		= (0xFU << BK4819_REG_30_SHIFT_ENABLE_PLL_VCO),
	BK4819_REG_30_DISABLE_PLL_VCO		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_PLL_VCO),
	BK4819_REG_30_ENABLE_PA_GAIN		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_PA_GAIN),
	BK4819_REG_30_DISABLE_PA_GAIN		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_PA_GAIN),
	BK4819_REG_30_ENABLE_MIC_ADC		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_MIC_ADC),
	BK4819_REG_30_DISABLE_MIC_ADC		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_MIC_ADC),
	BK4819_REG_30_ENABLE_TX_DSP		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_TX_DSP),
	BK4819_REG_30_DISABLE_TX_DSP		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_TX_DSP),
	BK4819_REG_30_ENABLE_RX_DSP		= (0x1U << BK4819_REG_30_SHIFT_ENABLE_RX_DSP),
	BK4819_REG_30_DISABLE_RX_DSP		= (0x0U << BK4819_REG_30_SHIFT_ENABLE_RX_DSP),
};

// REG 3F

#define BK4819_REG_3F_SHIFT_FSK_TX_FINISHED		15
#define BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_EMPTY	14
#define BK4819_REG_3F_SHIFT_FSK_RX_FINISHED		13
#define BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_FULL	12
#define BK4819_REG_3F_SHIFT_DTMF_5TONE_FOUND		11
#define BK4819_REG_3F_SHIFT_CxCSS_TAIL			10
#define BK4819_REG_3F_SHIFT_CDCSS_FOUND			9
#define BK4819_REG_3F_SHIFT_CDCSS_LOST			8
#define BK4819_REG_3F_SHIFT_CTCSS_FOUND			7
#define BK4819_REG_3F_SHIFT_CTCSS_LOST			6
#define BK4819_REG_3F_SHIFT_VOX_FOUND			5
#define BK4819_REG_3F_SHIFT_VOX_LOST			4
#define BK4819_REG_3F_SHIFT_SQUELCH_FOUND		3
#define BK4819_REG_3F_SHIFT_SQUELCH_LOST		2
#define BK4819_REG_3F_SHIFT_FSK_RX_SYNC			1

#define BK4819_REG_3F_MASK_FSK_TX_FINISHED		(1U << BK4819_REG_3F_SHIFT_FSK_TX)
#define BK4819_REG_3F_MASK_FSK_FIFO_ALMOST_EMPTY	(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_3F_MASK_FSK_RX_FINISHED		(1U << BK4819_REG_3F_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_3F_MASK_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_3F_MASK_DTMF_5TONE_FOUND		(1U << BK4819_REG_3F_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_3F_MASK_CxCSS_TAIL			(1U << BK4819_REG_3F_SHIFT_CxCSS_TAIL)
#define BK4819_REG_3F_MASK_CDCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CDCSS_FOUND)
#define BK4819_REG_3F_MASK_CDCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CDCSS_LOST)
#define BK4819_REG_3F_MASK_CTCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CTCSS_FOUND)
#define BK4819_REG_3F_MASK_CTCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CTCSS_LOST)
#define BK4819_REG_3F_MASK_VOX_FOUND			(1U << BK4819_REG_3F_SHIFT_VOX_FOUND)
#define BK4819_REG_3F_MASK_VOX_LOST			(1U << BK4819_REG_3F_SHIFT_VOX_LOST)
#define BK4819_REG_3F_MASK_SQUELCH_FOUND		(1U << BK4819_REG_3F_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_3F_MASK_SQUELCH_LOST			(1U << BK4819_REG_3F_SHIFT_SQUELCH_LOST)
#define BK4819_REG_3F_MASK_FSK_RX_SYNC			(1U << BK4819_REG_3F_SHIFT_FSK_RX_SYNC)

#define BK4819_REG_3F_FSK_TX_FINISHED			(1U << BK4819_REG_3F_SHIFT_FSK_TX_FINISHED)
#define BK4819_REG_3F_FSK_FIFO_ALMOST_EMPTY		(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_EMPTY)
#define BK4819_REG_3F_FSK_RX_FINISHED			(1U << BK4819_REG_3F_SHIFT_FSK_RX_FINISHED)
#define BK4819_REG_3F_FSK_FIFO_ALMOST_FULL		(1U << BK4819_REG_3F_SHIFT_FSK_FIFO_ALMOST_FULL)
#define BK4819_REG_3F_DTMF_5TONE_FOUND			(1U << BK4819_REG_3F_SHIFT_DTMF_5TONE_FOUND)
#define BK4819_REG_3F_CxCSS_TAIL			(1U << BK4819_REG_3F_SHIFT_CxCSS_TAIL)
#define BK4819_REG_3F_CDCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CDCSS_FOUND)
#define BK4819_REG_3F_CDCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CDCSS_LOST)
#define BK4819_REG_3F_CTCSS_FOUND			(1U << BK4819_REG_3F_SHIFT_CTCSS_FOUND)
#define BK4819_REG_3F_CTCSS_LOST			(1U << BK4819_REG_3F_SHIFT_CTCSS_LOST)
#define BK4819_REG_3F_VOX_FOUND				(1U << BK4819_REG_3F_SHIFT_VOX_FOUND)
#define BK4819_REG_3F_VOX_LOST				(1U << BK4819_REG_3F_SHIFT_VOX_LOST)
#define BK4819_REG_3F_SQUELCH_FOUND			(1U << BK4819_REG_3F_SHIFT_SQUELCH_FOUND)
#define BK4819_REG_3F_SQUELCH_LOST			(1U << BK4819_REG_3F_SHIFT_SQUELCH_LOST)
#define BK4819_REG_3F_FSK_RX_SYNC			(1U << BK4819_REG_3F_SHIFT_FSK_RX_SYNC)

// REG 51

#define BK4819_REG_51_SHIFT_ENABLE_CxCSS	15
#define BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT	14
#define BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY	13
#define BK4819_REG_51_SHIFT_CxCSS_MODE		12
#define BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH	11
#define BK4819_REG_51_SHIFT_1050HZ_DETECTION	10
#define BK4819_REG_51_SHIFT_AUTO_CDCSS_BW	9
#define BK4819_REG_51_SHIFT_AUTO_CTCSS_BW	8
#define BK4819_REG_51_SHIFT_CxCSS_TX_GAIN1	0

#define BK4819_REG_51_MASK_ENABLE_CxCSS		(0x01U << BK4819_REG_51_SHIFT_ENABLE_CxCSS)
#define BK4819_REG_51_MASK_GPIO6_PIN2_INPUT	(0x01U << BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT)
#define BK4819_REG_51_MASK_TX_CDCSS_POLARITY	(0x01U << BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY)
#define BK4819_REG_51_MASK_CxCSS_MODE		(0x01U << BK4819_REG_51_SHIFT_CxCSS_MODE)
#define BK4819_REG_51_MASK_CDCSS_BIT_WIDTH	(0x01U << BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH)
#define BK4819_REG_51_MASK_1050HZ_DETECTION	(0x01U << BK4819_REG_51_SHIFT_1050HZ_DETECTION)
#define BK4819_REG_51_MASK_AUTO_CDCSS_BW	(0x01U << BK4819_REG_51_SHIFT_AUTO_CDCSS_BW)
#define BK4819_REG_51_MASK_AUTO_CTCSS_BW	(0x01U << BK4819_REG_51_SHIFT_AUTO_CTCSS_BW)
#define BK4819_REG_51_MASK_CxCSS_TX_GAIN1	(0x7FU << BK4819_REG_51_SHIFT_CxCSS_TX_GAIN1)

enum {
	BK4819_REG_51_ENABLE_CxCSS		= (1U << BK4819_REG_51_SHIFT_ENABLE_CxCSS),
	BK4819_REG_51_DISABLE_CxCSS		= (0U << BK4819_REG_51_SHIFT_ENABLE_CxCSS),

	BK4819_REG_51_GPIO6_PIN2_INPUT		= (1U << BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT),
	BK4819_REG_51_GPIO6_PIN2_NORMAL		= (0U << BK4819_REG_51_SHIFT_GPIO6_PIN2_INPUT),

	BK4819_REG_51_TX_CDCSS_NEGATIVE		= (1U << BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY),
	BK4819_REG_51_TX_CDCSS_POSITIVE		= (0U << BK4819_REG_51_SHIFT_TX_CDCSS_POLARITY),

	BK4819_REG_51_MODE_CTCSS		= (1U << BK4819_REG_51_SHIFT_CxCSS_MODE),
	BK4819_REG_51_MODE_CDCSS		= (0U << BK4819_REG_51_SHIFT_CxCSS_MODE),

	BK4819_REG_51_CDCSS_24_BIT		= (1U << BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH),
	BK4819_REG_51_CDCSS_23_BIT		= (0U << BK4819_REG_51_SHIFT_CDCSS_BIT_WIDTH),

	BK4819_REG_51_1050HZ_DETECTION		= (1U << BK4819_REG_51_SHIFT_1050HZ_DETECTION),
	BK4819_REG_51_1050HZ_NO_DETECTION	= (0U << BK4819_REG_51_SHIFT_1050HZ_DETECTION),

	BK4819_REG_51_AUTO_CDCSS_BW_DISABLE	= (1U << BK4819_REG_51_SHIFT_AUTO_CDCSS_BW),
	BK4819_REG_51_AUTO_CDCSS_BW_ENABLE	= (0U << BK4819_REG_51_SHIFT_AUTO_CDCSS_BW),

	BK4819_REG_51_AUTO_CTCSS_BW_DISABLE	= (1U << BK4819_REG_51_SHIFT_AUTO_CTCSS_BW),
	BK4819_REG_51_AUTO_CTCSS_BW_ENABLE	= (0U << BK4819_REG_51_SHIFT_AUTO_CTCSS_BW),
};

// REG 70

#define BK4819_REG_70_SHIFT_ENABLE_TONE1	15
#define BK4819_REG_70_SHIFT_TONE1_TUNING_GAIN	8
#define BK4819_REG_70_SHIFT_ENABLE_TONE2	7
#define BK4819_REG_70_SHIFT_TONE2_TUNING_GAIN	0

#define BK4819_REG_70_MASK_ENABLE_TONE1		(0x01U << BK4819_REG_70_SHIFT_ENABLE_TONE1)
#define BK4819_REG_70_MASK_TONE1_TUNING_GAIN	(0x7FU << BK4819_REG_70_SHIFT_TONE1_TUNING_GAIN)
#define BK4819_REG_70_MASK_ENABLE_TONE2		(0x01U << BK4819_REG_70_SHIFT_ENABLE_TONE2)
#define BK4819_REG_70_MASK_TONE2_TUNING_GAIN	(0x7FU << BK4819_REG_70_SHIFT_TONE2_TUNING_GAIN)

enum {
	BK4819_REG_70_ENABLE_TONE1		= (1U << BK4819_REG_70_SHIFT_ENABLE_TONE1),
	BK4819_REG_70_ENABLE_TONE2		= (1U << BK4819_REG_70_SHIFT_ENABLE_TONE2),
};

#endif

