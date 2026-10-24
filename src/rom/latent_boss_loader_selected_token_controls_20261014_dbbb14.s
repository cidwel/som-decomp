; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB14
boss_lz_controls_dbbb14:
    ; backreference count 4, distance 507
    .byte $85, $FA
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
