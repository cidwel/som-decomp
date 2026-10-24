; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A14A
boss_lz_controls_dba14a:
    ; backreference count 3, distance 496
    .byte $81, $EF
    ; backreference count 3, distance 197
    .byte $80, $C4
    ; literal count 45; subsequent asset bytes excluded
    .byte $2C
