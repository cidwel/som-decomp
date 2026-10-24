.setcpu "65816"
.segment "CODE"
.org $2F35
map_control_0f2f35:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
