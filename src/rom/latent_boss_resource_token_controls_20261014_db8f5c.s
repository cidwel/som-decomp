; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8F5C
boss_lz_controls_db8f5c:
    ; backreference count 4, distance 22
    .byte $90, $15
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
