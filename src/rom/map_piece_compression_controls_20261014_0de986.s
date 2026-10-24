.setcpu "65816"
.segment "CODE"
.org $E986
map_control_0de986:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
