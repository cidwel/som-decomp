.setcpu "65816"
.segment "CODE"
.org $E104
map_control_0de104:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
