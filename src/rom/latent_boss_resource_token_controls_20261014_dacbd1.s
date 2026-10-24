; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBD1
boss_lz_controls_dacbd1:
    ; backreference count 3, distance 549
    .byte $82, $24
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
