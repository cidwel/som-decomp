.setcpu "65816"
.segment "CODE"
.org $24E5
map_control_0d24e5:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
