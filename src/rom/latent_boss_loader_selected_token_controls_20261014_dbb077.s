; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B077
boss_lz_controls_dbb077:
    ; backreference count 3, distance 195
    .byte $80, $C2
    ; literal count 71; subsequent asset bytes excluded
    .byte $46
