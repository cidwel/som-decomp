; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $017F
boss_lz_controls_db017f:
    ; backreference count 5, distance 6
    .byte $A0, $05
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
