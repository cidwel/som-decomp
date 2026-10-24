; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC44
boss_lz_controls_dbac44:
    ; backreference count 3, distance 189
    .byte $80, $BC
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
