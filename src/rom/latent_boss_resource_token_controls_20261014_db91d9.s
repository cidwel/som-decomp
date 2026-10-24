; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $91D9
boss_lz_controls_db91d9:
    ; backreference count 4, distance 767
    .byte $92, $FE
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
