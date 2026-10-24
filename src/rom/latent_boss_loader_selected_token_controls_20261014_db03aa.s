; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03AA
boss_lz_controls_db03aa:
    ; backreference count 3, distance 1035
    .byte $84, $0A
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
