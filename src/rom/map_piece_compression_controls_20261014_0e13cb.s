.setcpu "65816"
.segment "CODE"
.org $13CB
map_control_0e13cb:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
