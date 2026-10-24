; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF7E
boss_lz_controls_dbcf7e:
    ; backreference count 3, distance 50
    .byte $80, $31
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
