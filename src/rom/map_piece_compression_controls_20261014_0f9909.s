.setcpu "65816"
.segment "CODE"
.org $9909
map_control_0f9909:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
