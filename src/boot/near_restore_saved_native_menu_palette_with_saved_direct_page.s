; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-palette-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0641d = $C0641D

.segment "CODE"
.org $331F
near_restore_saved_native_menu_palette_with_saved_direct_page:
    phd
    php
    rep #$20
    sep #$20
    jsl f:routine_c0641d
    plp
    pld
    rts
