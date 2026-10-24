.setcpu "65816"
.segment "CODE"
.org $82D0
map_control_0f82d0:
    .byte $D7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
