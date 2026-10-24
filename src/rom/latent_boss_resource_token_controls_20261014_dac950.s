; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C950
boss_lz_controls_dac950:
    ; backreference count 3, distance 161
    .byte $80, $A0
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
