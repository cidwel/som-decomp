; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCE7
boss_lz_controls_dabce7:
    ; backreference count 4, distance 22
    .byte $84, $15
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
