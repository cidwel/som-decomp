.setcpu "65816"
.segment "CODE"
.org $78A7
map_control_0f78a7:
    .byte $F2 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $CB ; same-value copy count/distance
