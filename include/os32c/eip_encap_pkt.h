/**
Software License Agreement (proprietary)

\file      eip_types.cpp
\authors   Kareem Shehata <kshehata@clearpathrobotics.com>
\copyright Copyright (c) 2015, Clearpath Robotics, Inc., All rights reserved.

Redistribution and use in source and binary forms, with or without modification, is not permitted without the
express permission of Clearpath Robotics.
*/

#ifndef OS32C_EIP_ENCAP_PKT_H
#define OS32C_EIP_ENCAP_PKT_H

#include <boost/asio.hpp>

#include "os32c/eip_types.h"

/**
 * Representation of an EtherNet/IP Encapsulation Packet
 */
class EIPEncapPkt
{
public:

  /**
   * Construct an encapsulation packet
   */
  EIPEncapPkt(EIP_UINT command = 0, EIP_UDINT session_handle = 0)
  {
    memset(&header_, 0, sizeof(header_));
    header_.command = command;
    header_.session_handle = session_handle;
  }

  /**
   * Get the command value from this packet
   * @returns command value
   */
  EIP_UINT getCommand() const
  {
    return header_.command;
  }

  /**
   * Set the command value for this packet
   * @param command Command value to use
   */
  void setCommand(EIP_UINT command)
  {
    header_.command = command;
  }

  /**
   * Get the session handle from this packet
   * @returns session handle value
   */
  EIP_UDINT getSessionHandle() const
  {
    return header_.session_handle;
  }

  /**
   * Set the session handle for this packet
   * @param session_handle Session handle to use
   */
  void setSessionHandle(EIP_UDINT session_handle)
  {
    header_.session_handle = session_handle;
  }

  /**
   * Get the status from this packet
   * @returns status value
   */
  EIP_DWORD getStatus() const
  {
    return header_.status;
  }

  /**
   * Set the status for this packet
   * @param status Status value to use
   */
  void setStatus(EIP_DWORD status)
  {
    header_.status = status;
  }

  /**
   * Get the options from this packet
   * @returns options value
   */
  EIP_DWORD getOptions() const
  {
    return header_.options;
  }

  /**
   * Set the options for this packet
   * @param options Options value to use
   */
  void setOptions(EIP_DWORD options)
  {
    header_.options = options;
  }

  /**
   * Get the size of this packet
   * @returns size of packet in bytes
   */
  size_t getSize() const
  {
    return sizeof(header_);
  }

  boost::asio::const_buffer serialize() const
  {
    return boost::asio::const_buffer(&header_, sizeof(header_));
  }
  
private:
  EIP_ENCAP_HEADER header_;
};

#endif  // OS32C_EIP_ENCAP_PKT_H