; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7D3
boss_lz_controls_dbb7d3:
    ; backreference count 3, distance 54
    .byte $80, $35
    ; backreference count 5, distance 55
    .byte $88, $36
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
