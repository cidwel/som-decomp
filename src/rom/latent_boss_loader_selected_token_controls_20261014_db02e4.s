; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02E4
boss_lz_controls_db02e4:
    ; backreference count 3, distance 180
    .byte $80, $B3
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
