.setcpu "65816"
.segment "CODE"
.org $6FF4
map_control_0c6ff4:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
