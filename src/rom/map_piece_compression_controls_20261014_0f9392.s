.setcpu "65816"
.segment "CODE"
.org $9392
map_control_0f9392:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
