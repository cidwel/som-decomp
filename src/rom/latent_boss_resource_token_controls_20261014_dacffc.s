; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFFC
boss_lz_controls_dacffc:
    ; backreference count 3, distance 91
    .byte $80, $5A
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
