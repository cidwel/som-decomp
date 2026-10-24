; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF8D
boss_lz_controls_dbcf8d:
    ; backreference count 3, distance 450
    .byte $81, $C1
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
