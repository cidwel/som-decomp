; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AAED
boss_lz_controls_dbaaed:
    ; backreference count 3, distance 965
    .byte $83, $C4
    ; backreference count 3, distance 113
    .byte $80, $70
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
