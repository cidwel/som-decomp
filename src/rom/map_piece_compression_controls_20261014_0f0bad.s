.setcpu "65816"
.segment "CODE"
.org $0BAD
map_control_0f0bad:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
