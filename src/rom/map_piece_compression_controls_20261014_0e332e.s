.setcpu "65816"
.segment "CODE"
.org $332E
map_control_0e332e:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
