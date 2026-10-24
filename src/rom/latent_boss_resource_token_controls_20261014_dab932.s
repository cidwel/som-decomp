; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B932
boss_lz_controls_dab932:
    ; backreference count 3, distance 111
    .byte $80, $6E
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
