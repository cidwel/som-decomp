.setcpu "65816"
.segment "CODE"
.org $DEE2
map_control_0fdee2:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E4 ; previous-row copy count
