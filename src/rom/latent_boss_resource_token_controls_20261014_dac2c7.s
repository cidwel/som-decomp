; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C2C7
boss_lz_controls_dac2c7:
    ; backreference count 3, distance 4
    .byte $80, $03
    ; literal count 69; subsequent asset bytes excluded
    .byte $44
