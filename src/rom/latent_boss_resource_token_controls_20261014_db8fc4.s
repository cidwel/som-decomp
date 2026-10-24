; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8FC4
boss_lz_controls_db8fc4:
    ; backreference count 3, distance 177
    .byte $80, $B0
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D
