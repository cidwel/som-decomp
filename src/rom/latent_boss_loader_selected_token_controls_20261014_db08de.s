; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08DE
boss_lz_controls_db08de:
    ; backreference count 5, distance 213
    .byte $A0, $D4
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
