; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A41A
boss_lz_controls_dba41a:
    ; backreference count 4, distance 58
    .byte $88, $39
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
