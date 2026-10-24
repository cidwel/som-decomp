.setcpu "65816"
.segment "CODE"
.org $A952
map_control_0fa952:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
