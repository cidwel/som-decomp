; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7AB
boss_lz_controls_dbd7ab:
    ; backreference count 3, distance 385
    .byte $81, $80
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
