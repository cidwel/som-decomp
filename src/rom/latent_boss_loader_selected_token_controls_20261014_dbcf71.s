; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF71
boss_lz_controls_dbcf71:
    ; backreference count 3, distance 1035
    .byte $84, $0A
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
