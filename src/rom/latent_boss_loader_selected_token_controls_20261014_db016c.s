; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $016C
boss_lz_controls_db016c:
    ; backreference count 6, distance 94
    .byte $B0, $5D
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
