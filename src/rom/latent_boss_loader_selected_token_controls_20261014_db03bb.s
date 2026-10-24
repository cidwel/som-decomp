; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03BB
boss_lz_controls_db03bb:
    ; backreference count 3, distance 127
    .byte $80, $7E
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
