.setcpu "65816"
.segment "CODE"
.org $742C
map_control_0c742c:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D6 ; same-value copy count/distance
