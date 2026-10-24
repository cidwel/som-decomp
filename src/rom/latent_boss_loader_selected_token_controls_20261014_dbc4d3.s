; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4D3
boss_lz_controls_dbc4d3:
    ; backreference count 18, distance 1
    .byte $F8, $00
    ; backreference count 18, distance 1
    .byte $F8, $00
    ; backreference count 4, distance 910
    .byte $8B, $8D
    ; literal count 73; subsequent asset bytes excluded
    .byte $48
