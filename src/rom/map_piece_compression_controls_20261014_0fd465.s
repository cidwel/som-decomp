.setcpu "65816"
.segment "CODE"
.org $D465
map_control_0fd465:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
