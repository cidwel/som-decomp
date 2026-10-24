; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0009
boss_lz_controls_db0009:
    ; backreference count 9, distance 1
    .byte $E0, $00
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
