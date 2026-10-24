; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04F1
boss_lz_controls_db04f1:
    ; backreference count 6, distance 1307
    .byte $B5, $1A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
