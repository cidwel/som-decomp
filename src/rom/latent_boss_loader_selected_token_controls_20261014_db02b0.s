; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02B0
boss_lz_controls_db02b0:
    ; backreference count 3, distance 105
    .byte $80, $68
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
