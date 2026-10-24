; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A198
boss_lz_controls_dba198:
    ; backreference count 3, distance 278
    .byte $81, $15
    ; backreference count 3, distance 225
    .byte $80, $E0
    ; literal count 42; subsequent asset bytes excluded
    .byte $29
