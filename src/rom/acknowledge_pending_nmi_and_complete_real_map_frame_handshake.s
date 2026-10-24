; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-entry-handshake.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B055
acknowledge_pending_nmi_and_complete_real_map_frame_handshake:
    sep #$30
acknowledge_pending_nmi_and_complete_real_map_frame_handshake_c0b057:
    bit a:$4210
    bpl acknowledge_pending_nmi_and_complete_real_map_frame_handshake_c0b057
    bit a:$4210
    .a8
    lda #$B1
    sta a:$4200
    .a8
    lda #$02
    sta $EC
acknowledge_pending_nmi_and_complete_real_map_frame_handshake_c0b068:
    bit $EC
    bne acknowledge_pending_nmi_and_complete_real_map_frame_handshake_c0b068
    stz $56
    stz $57
