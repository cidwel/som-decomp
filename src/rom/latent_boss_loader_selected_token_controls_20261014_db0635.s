; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0635
boss_lz_controls_db0635:
    ; backreference count 7, distance 17
    .byte $C0, $10
    ; backreference count 4, distance 1412
    .byte $95, $83
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
