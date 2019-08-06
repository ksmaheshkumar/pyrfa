/**
 *  OMMPost is an interface for posting OMM message to ADS/ADH cache
 */

#ifndef _OMMPOST_H
#define _OMMPOST_H

#include "StdAfx.h"
#include "common/Encoder.h"

class RDMFieldDict;

class OMMPost
{
public:
    OMMPost(rfa::sessionLayer::OMMConsumer* pOMMConsumer,
                   rfa::common::Handle *loginHandle,
                   const RDMFieldDict* dict,
                   rfa::logger::ComponentLogger& componentLogger);

    ~OMMPost();

    void    submitData(const rfa::common::RFA_String& item, const rfa::common::RFA_Vector<rfa::common::RFA_String>& fieldList, int mType, const std::string& msgType, const rfa::common::RFA_String& serviceName, const std::string& mapAction="", const std::string& mapKey="");
    void    directorySubmit(const UInt8 &mType=0);
    void    closeSubmit(const rfa::common::RFA_String& item);
    void    closeAllSubmit();
    void    serviceDownSubmit();
    void    clearPublishedItemList();
    void    setDebugMode(const bool &debug);
    void    cleanup();

private:
    rfa::sessionLayer::OMMConsumer      *_pOMMConsumer;
    Handle                              *_pLoginHandle;
    RFA_String                          _vendorName;
    RFA_Vector<rfa::common::RFA_String> *_pItemList;
    RFA_Vector<rfa::common::RFA_String> _itemList;
    RespMsg                             _respMsg;
    FieldList                           _fieldList;
    Encoder                             _encoder;
    RespStatus                          _respStatus;
    AttribInfo                          _attribInfo;
    QualityOfService                    _qos;
    Map                                 _map;
    Series                              _series;
    const RDMFieldDict                  *_pDict;
    bool                                _debug;
    rfa::common::RFA_String             _log;

private:
    // Declared, but not implemented to prevent default behavior generated by compiler
    OMMPost( const OMMPost & );
    OMMPost & operator=( const OMMPost & );
    rfa::logger::ComponentLogger        &_componentLogger;
};

#endif // _OMMPOST_H