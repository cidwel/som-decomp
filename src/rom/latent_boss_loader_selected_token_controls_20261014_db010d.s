; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $010D
boss_lz_controls_db010d:
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
