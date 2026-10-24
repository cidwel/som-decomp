; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04F5
boss_lz_controls_db04f5:
    ; backreference count 4, distance 1360
    .byte $95, $4F
    ; backreference count 3, distance 402
    .byte $81, $91
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
