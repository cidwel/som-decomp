.setcpu "65816"
.segment "CODE"
.org $E7D9
map_control_0de7d9:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
