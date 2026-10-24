; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $006E
boss_lz_controls_db006e:
    ; backreference count 4, distance 28
    .byte $90, $1B
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
