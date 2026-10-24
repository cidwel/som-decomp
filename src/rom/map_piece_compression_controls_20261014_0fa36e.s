.setcpu "65816"
.segment "CODE"
.org $A36E
map_control_0fa36e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
