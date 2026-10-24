; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A1C7
boss_lz_controls_dba1c7:
    ; backreference count 4, distance 1770
    .byte $8E, $E9
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
