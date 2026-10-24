; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04D4
boss_lz_controls_db04d4:
    ; backreference count 5, distance 605
    .byte $A2, $5C
    ; backreference count 3, distance 1080
    .byte $84, $37
    ; backreference count 3, distance 625
    .byte $82, $70
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
