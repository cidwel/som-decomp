; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0777
boss_lz_controls_db0777:
    ; backreference count 4, distance 2281
    .byte $98, $E8
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
