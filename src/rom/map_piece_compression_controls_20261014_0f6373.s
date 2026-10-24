.setcpu "65816"
.segment "CODE"
.org $6373
map_control_0f6373:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
