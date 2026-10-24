.setcpu "65816"
.segment "CODE"
.org $7E4A
map_control_0f7e4a:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
