; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $074C
boss_lz_controls_db074c:
    ; backreference count 4, distance 6
    .byte $90, $05
    ; backreference count 3, distance 247
    .byte $80, $F6
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
