; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $988A
boss_lz_controls_db988a:
    ; backreference count 4, distance 54
    .byte $90, $35
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
