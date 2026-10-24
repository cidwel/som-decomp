.setcpu "65816"
.segment "CODE"
.org $7B47
map_control_0f7b47:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count
