.setcpu "65816"
.segment "CODE"
.org $DD69
map_control_0fdd69:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
