; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3AF
boss_lz_controls_daf3af:
    ; backreference count 9, distance 3251
    .byte $EC, $B2
    ; backreference count 10, distance 111
    .byte $F0, $6E
    ; backreference count 3, distance 1089
    .byte $84, $40
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
