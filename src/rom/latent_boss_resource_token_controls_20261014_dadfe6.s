; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFE6
boss_lz_controls_dadfe6:
    ; backreference count 3, distance 40
    .byte $80, $27
    ; literal count 52; subsequent asset bytes excluded
    .byte $33
