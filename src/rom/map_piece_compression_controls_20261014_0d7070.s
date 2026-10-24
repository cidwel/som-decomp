.setcpu "65816"
.segment "CODE"
.org $7070
map_control_0d7070:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
