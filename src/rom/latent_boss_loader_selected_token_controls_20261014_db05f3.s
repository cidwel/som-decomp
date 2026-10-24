; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05F3
boss_lz_controls_db05f3:
    ; backreference count 3, distance 1703
    .byte $86, $A6
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
