; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00F5
boss_lz_controls_db00f5:
    ; backreference count 3, distance 234
    .byte $80, $E9
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
