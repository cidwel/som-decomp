.setcpu "65816"
.segment "CODE"
.org $DA91
map_control_0fda91:
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
