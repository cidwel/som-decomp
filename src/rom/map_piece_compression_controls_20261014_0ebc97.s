.setcpu "65816"
.segment "CODE"
.org $BC97
map_control_0ebc97:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E2 ; previous-row copy count
