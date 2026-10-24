; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09EC
boss_lz_controls_db09ec:
    ; backreference count 5, distance 323
    .byte $A1, $42
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
