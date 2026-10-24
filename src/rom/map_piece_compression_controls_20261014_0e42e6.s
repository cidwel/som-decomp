.setcpu "65816"
.segment "CODE"
.org $42E6
map_control_0e42e6:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
