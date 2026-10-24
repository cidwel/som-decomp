; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0372
boss_lz_controls_db0372:
    ; backreference count 3, distance 6
    .byte $80, $05
    ; backreference count 3, distance 478
    .byte $81, $DD
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
