/*
 * This file is part of PCAPdroid.
 *
 * PCAPdroid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PCAPdroid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PCAPdroid.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2020-21 - Emanuele Faranda
 */

#ifndef __MY_PCAP_H__
#define __MY_PCAP_H__

#include <stdlib.h>
#include <stdint.h>

typedef struct pcap_hdr_s {
    uint32_t magic_number;
    uint16_t version_major;
    uint16_t version_minor;
    int32_t thiszone;
    uint32_t sigfigs;
    uint32_t snaplen;
    uint32_t network;
} __packed pcap_hdr_s;

typedef struct pcaprec_hdr_s {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t incl_len;
    uint32_t orig_len;
} __packed pcaprec_hdr_s;

void pcap_build_hdr(struct pcap_hdr_s *pcap_hdr);
int pcap_rec_size(int pkt_len);
void pcap_dump_rec(u_char *buffer, const u_char *pkt, int pkt_len);

#endif // __MY_PCAP_H__
