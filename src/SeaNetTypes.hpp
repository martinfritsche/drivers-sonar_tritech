#ifndef _SEANET_TYPES_H_
#define _SEANET_TYPES_H_

#include <base/angle.h>
#include <stdint.h>

namespace sea_net
{
    struct VersionData
    {
        uint8_t softwareVersion;
        uint8_t infoBits;
        uint8_t serialNr;
        uint8_t nodeID;
        uint32_t programmLength;
        uint16_t programmChecksum;
    };

    enum DeviceType
    {
        IMAGINGSONAR = 2,
        SIDESCAN = 10,
        SUBBOTTOM = 15,
        PROFILINGSONAR = 20,
        BATHYMETER = 40,
    };

    enum PacketType{
        mtNull = 0,
        mtVersionData, mtHeadData, mtSpectData, mtAlive, 
        mtPrgAck, mtBBUserData, mtTestData, mtAuxData, mtAdcData,
        mtLdcReq, na11, na12, mtLanStatus, mtSetTime, mtTimeout,
        mtReBoot, mtPerformanceData, na18, mtHeadCommand, mtEraseSector,
        mtProgBlock, mtCopyBootBlk, mtSendVersion, mtSendBBUser, mtSendData,
        mtSendPreferenceData
    };

    struct ProfilingConfig
    {
        base::Angle left_limit;
        base::Angle right_limit;
        base::Angle angular_resolution; 

        unsigned int select_channel;
        unsigned int frequency_chan1;
        unsigned int frequency_chan2;
        
        double max_distance;
        double min_distance;
        double speed_of_sound;
        double gain;
        double filt_gain;
        
        bool continous;
        
        ProfilingConfig() : 
            left_limit(base::Angle::fromRad(M_PI)),
            right_limit(base::Angle::fromRad(-M_PI)),
            angular_resolution(base::Angle::fromRad(5.0/180.0*M_PI)),
            select_channel(1),
            frequency_chan1(600000),
            frequency_chan2(1200000),
            max_distance(15.0),
            min_distance(1.0),
            speed_of_sound(1500.0),
            gain(0.2),
            filt_gain(0.01),
            continous(false)
        {};
      
        bool operator==(const ProfilingConfig &other) const
        {
            return (other.left_limit == left_limit &&
                    other.right_limit == right_limit &&
                    other.angular_resolution == angular_resolution &&
                    other.select_channel == select_channel &&
                    other.frequency_chan1 == frequency_chan1 &&
                    other.frequency_chan2 == frequency_chan2 &&
                    other.max_distance == max_distance && 
                    other.min_distance == min_distance && 
                    other.speed_of_sound== speed_of_sound &&
                    other.gain == gain &&
                    other.filt_gain == filt_gain);
        };
        
        bool operator!=(const ProfilingConfig &other) const
        {
            return !(other == *this);
        };
    };

    //some values are not working for the micron dst like lock_out time
    //invert, etc
    struct MicronConfig
    {
        base::Angle left_limit;
        base::Angle right_limit;
        base::Angle angular_resolution; 

        double max_distance;
        double min_distance;
        double resolution;
        double speed_of_sound;
        double gain;

        bool low_resolution;
        bool continous;
        bool invert;

        MicronConfig():
            left_limit(base::Angle::fromRad(M_PI)),
            right_limit(base::Angle::fromRad(-M_PI)),
            angular_resolution(base::Angle::fromRad(5.0/180.0*M_PI)),
            max_distance(15.0),
            min_distance(1.0),
            resolution(0.1),
            speed_of_sound(1500.0),
            gain(0.4),
            low_resolution(false),
            continous(true),
            invert(false)
        {};

        bool operator==(const MicronConfig &other) const
        {
            return (other.left_limit == left_limit &&
                    other.right_limit == right_limit &&
                    other.angular_resolution == angular_resolution &&
                    other.max_distance == max_distance && 
                    other.min_distance == min_distance && 
                    other.resolution == resolution &&
                    other.speed_of_sound== speed_of_sound &&
                    other.gain == gain &&
                    other.low_resolution == low_resolution &&
                    other.continous == continous &&
                    other.invert == invert);
        };
        bool operator!=(const MicronConfig &other) const
        {
            return !(other == *this);
        };
    };
}
#endif 
