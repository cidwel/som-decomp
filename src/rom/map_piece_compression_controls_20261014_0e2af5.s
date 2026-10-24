.setcpu "65816"
.segment "CODE"
.org $2AF5
map_control_0e2af5:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $CC ; same-value copy count/distance
