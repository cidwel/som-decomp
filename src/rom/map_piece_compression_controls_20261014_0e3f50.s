.setcpu "65816"
.segment "CODE"
.org $3F50
map_control_0e3f50:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
