; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08BA
boss_lz_controls_db08ba:
    ; backreference count 5, distance 16
    .byte $A0, $0F
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
