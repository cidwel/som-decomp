; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03D5
boss_lz_controls_db03d5:
    ; backreference count 6, distance 101
    .byte $B0, $64
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
