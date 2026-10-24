; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D007
boss_lz_controls_dad007:
    ; backreference count 3, distance 41
    .byte $80, $28
    ; literal count 23; subsequent asset bytes excluded
    .byte $16
