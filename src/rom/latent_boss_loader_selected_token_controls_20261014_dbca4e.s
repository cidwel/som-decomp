; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA4E
boss_lz_controls_dbca4e:
    ; backreference count 3, distance 966
    .byte $83, $C5
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
