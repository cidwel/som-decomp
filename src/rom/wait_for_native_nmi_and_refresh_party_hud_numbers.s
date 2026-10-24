; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

request_frame_upload_and_wait_for_native_nmi = $E0F9
write_party_hud_numbers = $E339

.segment "CODE"
.org $E326
wait_for_native_nmi_and_refresh_party_hud_numbers:
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    jsr request_frame_upload_and_wait_for_native_nmi
    jsr write_party_hud_numbers
    plb
    rts
