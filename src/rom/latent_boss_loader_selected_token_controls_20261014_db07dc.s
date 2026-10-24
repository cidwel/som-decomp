; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07DC
boss_lz_controls_db07dc:
    ; backreference count 3, distance 1530
    .byte $85, $F9
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
