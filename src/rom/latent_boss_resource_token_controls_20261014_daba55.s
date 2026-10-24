; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA55
boss_lz_controls_daba55:
    ; backreference count 3, distance 470
    .byte $81, $D5
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
