.setcpu "65816"
.segment "CODE"
.org $E711
map_control_0fe711:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
