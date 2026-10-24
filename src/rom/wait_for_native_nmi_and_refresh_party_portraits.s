; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E6AC
wait_for_native_nmi_and_refresh_party_portraits:
    sep #$20
    .a8
    lda #$02
    sta $EC
wait_for_native_nmi_and_refresh_party_portraits_c1e6b2:
    bit $EC
    bne wait_for_native_nmi_and_refresh_party_portraits_c1e6b2
