.setcpu "65816"
.segment "CODE"
.org $60A8
map_control_0d60a8:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
