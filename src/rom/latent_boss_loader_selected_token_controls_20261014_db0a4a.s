; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A4A
boss_lz_controls_db0a4a:
    ; backreference count 6, distance 2751
    .byte $BA, $BE
    ; backreference count 6, distance 1378
    .byte $B5, $61
    ; backreference count 3, distance 1260
    .byte $84, $EB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
