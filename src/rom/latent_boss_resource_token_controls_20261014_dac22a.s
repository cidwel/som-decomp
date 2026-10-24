; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C22A
boss_lz_controls_dac22a:
    ; backreference count 10, distance 828
    .byte $9F, $3B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
