.setcpu "65816"
.segment "CODE"
.org $05F9
map_control_0f05f9:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
