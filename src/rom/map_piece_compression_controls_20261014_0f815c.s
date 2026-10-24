.setcpu "65816"
.segment "CODE"
.org $815C
map_control_0f815c:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
