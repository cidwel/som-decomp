; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A23D
boss_lz_controls_dba23d:
    ; backreference count 10, distance 653
    .byte $BA, $8C
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
