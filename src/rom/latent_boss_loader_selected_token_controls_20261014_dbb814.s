; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B814
boss_lz_controls_dbb814:
    ; backreference count 4, distance 748
    .byte $86, $EB
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
