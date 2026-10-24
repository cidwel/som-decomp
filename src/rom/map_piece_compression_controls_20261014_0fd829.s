.setcpu "65816"
.segment "CODE"
.org $D829
map_control_0fd829:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
