; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0601
boss_lz_controls_db0601:
    ; backreference count 5, distance 1405
    .byte $A5, $7C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
