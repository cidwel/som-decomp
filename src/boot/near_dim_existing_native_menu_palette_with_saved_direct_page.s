; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-palette-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0641a = $C0641A

.segment "CODE"
.org $3312
near_dim_existing_native_menu_palette_with_saved_direct_page:
    phd
    php
    rep #$20
    sep #$20
    jsl f:routine_c0641a
    plp
    pld
    rts
