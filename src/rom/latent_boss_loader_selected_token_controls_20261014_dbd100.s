; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D100
boss_lz_controls_dbd100:
    ; backreference count 3, distance 2052
    .byte $88, $03
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
