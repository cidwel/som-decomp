; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE2A
boss_lz_controls_dabe2a:
    ; backreference count 6, distance 9
    .byte $8C, $08
    ; literal count 57; subsequent asset bytes excluded
    .byte $38
