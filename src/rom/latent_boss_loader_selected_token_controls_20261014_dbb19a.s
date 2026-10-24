; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B19A
boss_lz_controls_dbb19a:
    ; backreference count 3, distance 671
    .byte $82, $9E
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
