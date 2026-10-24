; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0816
boss_lz_controls_db0816:
    ; backreference count 4, distance 2027
    .byte $97, $EA
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
