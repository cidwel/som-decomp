.setcpu "65816"
.segment "CODE"
.org $1FF9
map_control_0e1ff9:
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
