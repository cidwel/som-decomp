.setcpu "65816"
.segment "CODE"
.org $B5D4
map_control_0fb5d4:
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E4 ; previous-row copy count
