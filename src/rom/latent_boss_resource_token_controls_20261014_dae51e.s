; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E51E
boss_lz_controls_dae51e:
    ; backreference count 3, distance 1718
    .byte $86, $B5
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
