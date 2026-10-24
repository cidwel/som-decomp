; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A130
boss_lz_controls_dba130:
    ; backreference count 10, distance 1430
    .byte $BD, $95
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
