.setcpu "65816"
.segment "CODE"
.org $A51A
map_control_0fa51a:
    .byte $CA ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
