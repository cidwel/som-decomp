; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0752
boss_lz_controls_db0752:
    ; backreference count 3, distance 33
    .byte $80, $20
    ; backreference count 4, distance 1404
    .byte $95, $7B
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
