; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02D0
boss_lz_controls_db02d0:
    ; backreference count 6, distance 614
    .byte $B2, $65
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
