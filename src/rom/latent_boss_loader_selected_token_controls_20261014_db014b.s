; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $014B
boss_lz_controls_db014b:
    ; backreference count 4, distance 196
    .byte $90, $C3
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
