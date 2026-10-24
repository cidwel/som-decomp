; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01F0
boss_lz_controls_db01f0:
    ; backreference count 10, distance 9
    .byte $F0, $08
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
