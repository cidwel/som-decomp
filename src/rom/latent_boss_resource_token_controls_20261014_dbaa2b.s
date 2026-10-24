; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AA2B
boss_lz_controls_dbaa2b:
    ; backreference count 3, distance 795
    .byte $83, $1A
    ; backreference count 3, distance 523
    .byte $82, $0A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
