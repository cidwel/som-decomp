.setcpu "65816"
.segment "CODE"
.org $7196
map_control_0e7196:
    .byte $E2 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
