/*
 * See LICENSE for licensing information
 */

#ifndef SHD_TGEN_TRANSPORT_H_
#define SHD_TGEN_TRANSPORT_H_

#include "shd-tgen.h"

typedef enum _TGenTransportProtocol {
    TGEN_PROTOCOL_NONE, TGEN_PROTOCOL_TCP, TGEN_PROTOCOL_UDP,
    TGEN_PROTOCOL_PIPE, TGEN_PROTOCOL_SOCKETPAIR,
} TGenTransportProtocol;

typedef struct _TGenTransport TGenTransport;

typedef void (*TGenTransport_onBytesFunc)(gpointer data, gsize bytesRead, gsize bytesWritten);

TGenTransport* tgentransport_newActive(TGenPeer* proxy, TGenPeer* peer,
        TGenTransport_onBytesFunc notify, gpointer notifyData);
TGenTransport* tgentransport_newPassive(gint socketD, TGenPeer* peer,
        TGenTransport_onBytesFunc notify, gpointer notifyData);

void tgentransport_ref(TGenTransport* transport);
void tgentransport_unref(TGenTransport* transport);

gssize tgentransport_write(TGenTransport* transport, gpointer buffer, gsize length);
gssize tgentransport_read(TGenTransport* transport, gpointer buffer, gsize length);

gint transport_getDescriptor(TGenTransport* transport);
const gchar* tgentransport_toString(TGenTransport* transport);

#endif /* SHD_TGEN_TRANSPORT_H_ */
