; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08A0
boss_lz_controls_db08a0:
    ; backreference count 5, distance 3031
    .byte $AB, $D6
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
