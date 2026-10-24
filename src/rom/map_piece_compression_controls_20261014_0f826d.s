.setcpu "65816"
.segment "CODE"
.org $826D
map_control_0f826d:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
