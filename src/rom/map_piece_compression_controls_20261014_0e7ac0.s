.setcpu "65816"
.segment "CODE"
.org $7AC0
map_control_0e7ac0:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E7 ; previous-row copy count
