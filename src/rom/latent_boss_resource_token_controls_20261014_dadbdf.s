; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DBDF
boss_lz_controls_dadbdf:
    ; backreference count 9, distance 362
    .byte $B1, $69
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
