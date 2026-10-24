; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $091E
boss_lz_controls_db091e:
    ; backreference count 5, distance 3137
    .byte $AC, $40
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
