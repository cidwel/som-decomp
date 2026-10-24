.setcpu "65816"
.segment "CODE"
.org $92B0
map_control_0f92b0:
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
