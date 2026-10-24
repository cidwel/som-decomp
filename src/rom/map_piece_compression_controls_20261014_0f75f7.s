.setcpu "65816"
.segment "CODE"
.org $75F7
map_control_0f75f7:
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
