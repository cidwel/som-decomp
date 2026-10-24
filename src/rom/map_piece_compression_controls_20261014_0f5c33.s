.setcpu "65816"
.segment "CODE"
.org $5C33
map_control_0f5c33:
    .byte $EC ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
