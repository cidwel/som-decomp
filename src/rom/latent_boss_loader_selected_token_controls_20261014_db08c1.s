; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08C1
boss_lz_controls_db08c1:
    ; backreference count 7, distance 1759
    .byte $C6, $DE
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
