.setcpu "65816"
.segment "CODE"
.org $54EE
map_control_0d54ee:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
