; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E56E
boss_lz_controls_dae56e:
    ; backreference count 5, distance 420
    .byte $91, $A3
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
