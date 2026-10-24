.setcpu "65816"
.segment "CODE"
.org $33ED
map_control_0f33ed:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
