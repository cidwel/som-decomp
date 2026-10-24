; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0185
boss_lz_controls_db0185:
    ; backreference count 3, distance 160
    .byte $80, $9F
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
