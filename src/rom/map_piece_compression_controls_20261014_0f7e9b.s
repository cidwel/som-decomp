.setcpu "65816"
.segment "CODE"
.org $7E9B
map_control_0f7e9b:
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
