; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AF55
boss_lz_controls_dbaf55:
    ; backreference count 3, distance 360
    .byte $81, $67
    ; literal count 41; subsequent asset bytes excluded
    .byte $28
