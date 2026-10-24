; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D3E1
boss_lz_controls_dbd3e1:
    ; backreference count 3, distance 432
    .byte $81, $AF
    ; literal count 52; subsequent asset bytes excluded
    .byte $33
