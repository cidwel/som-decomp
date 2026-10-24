.setcpu "65816"
.segment "CODE"
.org $7DE9
map_control_0f7de9:
    .byte $E6 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
