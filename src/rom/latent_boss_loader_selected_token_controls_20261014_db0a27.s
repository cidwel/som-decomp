; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A27
boss_lz_controls_db0a27:
    ; backreference count 5, distance 2654
    .byte $AA, $5D
    ; backreference count 8, distance 41
    .byte $D0, $28
    ; backreference count 10, distance 2699
    .byte $FA, $8A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
