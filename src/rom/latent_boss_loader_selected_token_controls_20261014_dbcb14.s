; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB14
boss_lz_controls_dbcb14:
    ; backreference count 3, distance 174
    .byte $80, $AD
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
