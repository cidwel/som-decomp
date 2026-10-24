; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDFC
boss_lz_controls_dacdfc:
    ; backreference count 3, distance 69
    .byte $80, $44
    ; literal count 18; subsequent asset bytes excluded
    .byte $11
