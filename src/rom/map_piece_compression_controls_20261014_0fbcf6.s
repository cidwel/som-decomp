.setcpu "65816"
.segment "CODE"
.org $BCF6
map_control_0fbcf6:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
