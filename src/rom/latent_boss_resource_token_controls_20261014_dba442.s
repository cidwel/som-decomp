; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A442
boss_lz_controls_dba442:
    ; backreference count 3, distance 233
    .byte $80, $E8
    ; backreference count 4, distance 57
    .byte $88, $38
    ; backreference count 4, distance 56
    .byte $88, $37
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
