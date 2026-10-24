; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D62B
boss_lz_controls_dbd62b:
    ; backreference count 3, distance 89
    .byte $80, $58
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
