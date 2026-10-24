; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03DE
boss_lz_controls_db03de:
    ; backreference count 7, distance 65
    .byte $C0, $40
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
