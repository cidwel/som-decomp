; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A88D
boss_lz_controls_dba88d:
    ; backreference count 3, distance 358
    .byte $81, $65
    ; literal count 31; subsequent asset bytes excluded
    .byte $1E
