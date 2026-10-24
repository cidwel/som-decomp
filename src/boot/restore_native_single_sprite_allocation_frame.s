; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-single-sprite-allocate.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B72B
restore_native_single_sprite_allocation_frame:
    plb
    pla
    pla
    plp
    pld
    rts
