; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAC5
boss_lz_controls_dbbac5:
    ; backreference count 3, distance 738
    .byte $82, $E1
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
