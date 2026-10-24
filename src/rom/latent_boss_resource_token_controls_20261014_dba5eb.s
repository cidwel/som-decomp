; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A5EB
boss_lz_controls_dba5eb:
    ; backreference count 4, distance 263
    .byte $83, $06
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
