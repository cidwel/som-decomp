; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02A7
boss_lz_controls_db02a7:
    ; backreference count 4, distance 13
    .byte $90, $0C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
