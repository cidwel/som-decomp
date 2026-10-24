; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02D4
boss_lz_controls_db02d4:
    ; backreference count 3, distance 217
    .byte $80, $D8
    ; backreference count 4, distance 15
    .byte $90, $0E
    ; backreference count 3, distance 63
    .byte $80, $3E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
