; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $095D
boss_lz_controls_db095d:
    ; backreference count 5, distance 8
    .byte $A0, $07
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
