; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

wait_for_native_nmi_and_refresh_party_portraits = $E6AC

.segment "CODE"
.org $E6A8
refresh_party_portraits_long:
    jsr wait_for_native_nmi_and_refresh_party_portraits
    rtl
