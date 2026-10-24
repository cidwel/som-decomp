.setcpu "65816"
.segment "CODE"
.org $DFB1
map_control_0fdfb1:
    .byte $D6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
