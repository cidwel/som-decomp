.setcpu "65816"
.segment "CODE"
.org $1F13
map_control_0f1f13:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
