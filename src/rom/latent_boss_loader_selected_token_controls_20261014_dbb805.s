; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B805
boss_lz_controls_dbb805:
    ; backreference count 3, distance 930
    .byte $83, $A1
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
