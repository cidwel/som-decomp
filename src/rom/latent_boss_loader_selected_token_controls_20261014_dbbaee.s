; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAEE
boss_lz_controls_dbbaee:
    ; backreference count 3, distance 462
    .byte $81, $CD
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
