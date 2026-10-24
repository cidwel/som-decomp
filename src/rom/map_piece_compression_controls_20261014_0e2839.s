.setcpu "65816"
.segment "CODE"
.org $2839
map_control_0e2839:
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E1 ; previous-row copy count
