.setcpu "65816"
.segment "CODE"
.org $36A2
map_control_0e36a2:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
