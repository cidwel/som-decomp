; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6DB
boss_lz_controls_dbd6db:
    ; backreference count 10, distance 751
    .byte $9E, $EE
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
