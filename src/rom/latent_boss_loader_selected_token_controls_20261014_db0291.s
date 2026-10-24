; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0291
boss_lz_controls_db0291:
    ; backreference count 5, distance 7
    .byte $A0, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
