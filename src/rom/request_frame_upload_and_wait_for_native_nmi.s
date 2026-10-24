; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E0F9
request_frame_upload_and_wait_for_native_nmi:
    sep #$20
    .a8
    lda #$02
    sta $EC
request_frame_upload_and_wait_for_native_nmi_c1e0ff:
    bit $EC
    bne request_frame_upload_and_wait_for_native_nmi_c1e0ff
    rts
