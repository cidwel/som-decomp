; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F351
boss_lz_controls_daf351:
    ; backreference count 6, distance 91
    .byte $B0, $5A
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
