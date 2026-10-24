; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0D1E
boss_lz_controls_db0d1e:
    ; backreference count 64, distance 445
    .byte $FB, $BC
    ; literal count 65; subsequent asset bytes excluded
    .byte $40
