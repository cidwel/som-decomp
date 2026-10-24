; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $088C
boss_lz_controls_db088c:
    ; backreference count 4, distance 87
    .byte $90, $56
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
