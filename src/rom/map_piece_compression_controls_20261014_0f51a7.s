.setcpu "65816"
.segment "CODE"
.org $51A7
map_control_0f51a7:
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
