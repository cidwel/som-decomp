; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF3C
boss_lz_controls_dbcf3c:
    ; backreference count 4, distance 86
    .byte $90, $55
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
