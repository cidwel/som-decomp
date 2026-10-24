.setcpu "65816"
.segment "CODE"
.org $517A
map_control_0c517a:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
