; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA25
boss_lz_controls_dbca25:
    ; backreference count 3, distance 767
    .byte $82, $FE
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
