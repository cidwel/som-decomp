.setcpu "65816"
.segment "CODE"
.org $2E4C
map_control_0c2e4c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
