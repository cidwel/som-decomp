; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F37A
boss_lz_controls_daf37a:
    ; backreference count 3, distance 1801
    .byte $87, $08
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
