.setcpu "65816"
.segment "CODE"
.org $3B17
map_control_0e3b17:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
