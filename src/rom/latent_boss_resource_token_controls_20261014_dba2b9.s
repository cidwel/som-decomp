; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A2B9
boss_lz_controls_dba2b9:
    ; backreference count 3, distance 4
    .byte $80, $03
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
