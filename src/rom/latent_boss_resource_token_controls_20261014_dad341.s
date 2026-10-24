; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D341
boss_lz_controls_dad341:
    ; backreference count 3, distance 110
    .byte $80, $6D
    ; backreference count 4, distance 987
    .byte $8B, $DA
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
