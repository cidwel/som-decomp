; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB66
boss_lz_controls_dacb66:
    ; backreference count 4, distance 514
    .byte $8A, $01
    ; literal count 56; subsequent asset bytes excluded
    .byte $37
