; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE24
boss_lz_controls_dabe24:
    ; backreference count 5, distance 34
    .byte $88, $21
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
