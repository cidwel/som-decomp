; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0884
boss_lz_controls_db0884:
    ; backreference count 4, distance 360
    .byte $91, $67
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
