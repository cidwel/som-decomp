.setcpu "65816"
.segment "CODE"
.org $9D40
map_control_0f9d40:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
