; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A21C
boss_lz_controls_dba21c:
    ; backreference count 5, distance 407
    .byte $91, $96
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
