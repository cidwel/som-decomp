; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFF2
boss_lz_controls_dabff2:
    ; backreference count 4, distance 163
    .byte $84, $A2
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
