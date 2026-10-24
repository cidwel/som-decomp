; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0908
boss_lz_controls_db0908:
    ; backreference count 5, distance 1482
    .byte $A5, $C9
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
