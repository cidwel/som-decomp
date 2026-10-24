.setcpu "65816"
.segment "CODE"
.org $1256
map_control_0f1256:
    .byte $D1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
