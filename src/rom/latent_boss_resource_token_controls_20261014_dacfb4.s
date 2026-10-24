; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFB4
boss_lz_controls_dacfb4:
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
