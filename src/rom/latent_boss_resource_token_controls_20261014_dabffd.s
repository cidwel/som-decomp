; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFFD
boss_lz_controls_dabffd:
    ; backreference count 5, distance 161
    .byte $88, $A0
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
