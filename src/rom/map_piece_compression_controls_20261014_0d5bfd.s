.setcpu "65816"
.segment "CODE"
.org $5BFD
map_control_0d5bfd:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
