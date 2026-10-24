; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF50
boss_lz_controls_dbcf50:
    ; backreference count 3, distance 558
    .byte $82, $2D
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D
