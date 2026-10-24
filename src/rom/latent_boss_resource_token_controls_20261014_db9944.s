; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9944
boss_lz_controls_db9944:
    ; backreference count 5, distance 45
    .byte $A0, $2C
    ; backreference count 3, distance 720
    .byte $82, $CF
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
