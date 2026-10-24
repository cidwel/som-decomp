; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DED0
boss_lz_controls_daded0:
    ; backreference count 3, distance 1105
    .byte $84, $50
    ; literal count 75; subsequent asset bytes excluded
    .byte $4A
