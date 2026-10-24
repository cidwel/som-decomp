; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EBFE
boss_lz_controls_daebfe:
    ; backreference count 3, distance 718
    .byte $82, $CD
    ; literal count 38; subsequent asset bytes excluded
    .byte $25
