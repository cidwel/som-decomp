; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC4A
boss_lz_controls_dbcc4a:
    ; backreference count 3, distance 1221
    .byte $84, $C4
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A
