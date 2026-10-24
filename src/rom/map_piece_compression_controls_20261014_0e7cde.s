.setcpu "65816"
.segment "CODE"
.org $7CDE
map_control_0e7cde:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
