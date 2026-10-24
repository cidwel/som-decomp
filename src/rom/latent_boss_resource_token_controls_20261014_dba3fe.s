; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3FE
boss_lz_controls_dba3fe:
    ; backreference count 3, distance 885
    .byte $83, $74
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
