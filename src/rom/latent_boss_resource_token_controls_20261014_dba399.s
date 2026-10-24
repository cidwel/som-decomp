; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A399
boss_lz_controls_dba399:
    ; backreference count 4, distance 54
    .byte $88, $35
    ; backreference count 4, distance 53
    .byte $88, $34
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
