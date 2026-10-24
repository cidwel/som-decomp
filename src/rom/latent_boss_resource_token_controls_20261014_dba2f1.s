; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A2F1
boss_lz_controls_dba2f1:
    ; backreference count 3, distance 309
    .byte $81, $34
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
