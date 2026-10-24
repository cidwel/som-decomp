.setcpu "65816"
.segment "CODE"
.org $AF6A
map_control_0faf6a:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E3 ; previous-row copy count
