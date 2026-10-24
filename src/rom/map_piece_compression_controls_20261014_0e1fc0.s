.setcpu "65816"
.segment "CODE"
.org $1FC0
map_control_0e1fc0:
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
