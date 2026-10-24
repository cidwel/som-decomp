.setcpu "65816"
.segment "CODE"
.org $2807
map_control_0e2807:
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E4 ; previous-row copy count
