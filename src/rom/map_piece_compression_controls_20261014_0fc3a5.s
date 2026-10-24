.setcpu "65816"
.segment "CODE"
.org $C3A5
map_control_0fc3a5:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
