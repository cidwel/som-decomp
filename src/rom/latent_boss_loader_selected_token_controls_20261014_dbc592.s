; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C592
boss_lz_controls_dbc592:
    ; backreference count 18, distance 213
    .byte $F8, $D4
    ; backreference count 15, distance 1
    .byte $E0, $00
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
