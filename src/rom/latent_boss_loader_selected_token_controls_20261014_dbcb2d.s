; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB2D
boss_lz_controls_dbcb2d:
    ; backreference count 4, distance 52
    .byte $90, $33
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
