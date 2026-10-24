.setcpu "65816"
.segment "CODE"
.org $2007
map_control_0e2007:
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
