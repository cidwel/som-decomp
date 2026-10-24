; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-protocol-entry.md.
.setcpu "65816"
.smart
.a8
.i16

expand_selected_native_interface_overlay_row = $8EE0
routine_7ec870 = $C870

.segment "CODE"
.org $D52F
render_and_queue_native_interface_protocol_overlay:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    ldx a:$0306
    jsr expand_selected_native_interface_overlay_row
    ldx a:$0306
    jsr routine_7ec870
    plb
    plp
    pld
    rts
