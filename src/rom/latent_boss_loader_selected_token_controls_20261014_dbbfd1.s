; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFD1
boss_lz_controls_dbbfd1:
    ; backreference count 3, distance 798
    .byte $83, $1D
    ; literal count 37; subsequent asset bytes excluded
    .byte $24
