.setcpu "65816"
.segment "CODE"
.org $44A7
map_control_0c44a7:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
