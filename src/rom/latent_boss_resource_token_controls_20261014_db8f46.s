; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8F46
boss_lz_controls_db8f46:
    ; backreference count 4, distance 1
    .byte $90, $00
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
