; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9BD7
boss_lz_controls_db9bd7:
    ; backreference count 3, distance 65
    .byte $80, $40
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
