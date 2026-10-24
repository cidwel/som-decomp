; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06E1
boss_lz_controls_db06e1:
    ; backreference count 4, distance 1983
    .byte $97, $BE
    ; backreference count 4, distance 2134
    .byte $98, $55
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
