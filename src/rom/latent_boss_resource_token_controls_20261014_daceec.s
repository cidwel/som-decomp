; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEEC
boss_lz_controls_daceec:
    ; backreference count 3, distance 1963
    .byte $87, $AA
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
