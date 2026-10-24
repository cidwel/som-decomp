.setcpu "65816"
.segment "CODE"
.org $5D8C
map_control_0d5d8c:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $C9 ; same-value copy count/distance
