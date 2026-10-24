; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D12C
test_and_record_contact_event_edge_bit:
    phx
    pla
    pla
    bne test_and_record_contact_event_edge_bit_c1d133
    .a8
    lda #$01
test_and_record_contact_event_edge_bit_c1d133:
    bcc test_and_record_contact_event_edge_bit_c1d138
    asl
    asl
    asl
test_and_record_contact_event_edge_bit_c1d138:
    sta $00
    and a:$E04E,Y
    bne test_and_record_contact_event_edge_bit_c1d149
    lda $00
    ora a:$E04E,Y
    sta a:$E04E,Y
    .a8
    lda #$00
test_and_record_contact_event_edge_bit_c1d149:
    rts
