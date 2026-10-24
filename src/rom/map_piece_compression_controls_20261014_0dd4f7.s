.setcpu "65816"
.segment "CODE"
.org $D4F7
map_control_0dd4f7:
    .byte $CB ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
