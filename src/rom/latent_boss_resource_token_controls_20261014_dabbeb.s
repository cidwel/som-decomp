; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBEB
boss_lz_controls_dabbeb:
    ; backreference count 3, distance 145
    .byte $80, $90
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
