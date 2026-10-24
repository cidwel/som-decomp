.setcpu "65816"
.segment "CODE"
.org $774A
map_control_0c774a:
    .byte $D7 ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
