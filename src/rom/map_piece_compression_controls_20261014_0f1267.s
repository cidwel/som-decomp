.setcpu "65816"
.segment "CODE"
.org $1267
map_control_0f1267:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
