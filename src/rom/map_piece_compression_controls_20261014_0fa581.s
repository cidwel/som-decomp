.setcpu "65816"
.segment "CODE"
.org $A581
map_control_0fa581:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
