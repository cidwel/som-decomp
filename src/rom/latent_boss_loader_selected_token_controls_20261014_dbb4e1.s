; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B4E1
boss_lz_controls_dbb4e1:
    ; backreference count 3, distance 287
    .byte $81, $1E
    ; literal count 102; subsequent asset bytes excluded
    .byte $65
