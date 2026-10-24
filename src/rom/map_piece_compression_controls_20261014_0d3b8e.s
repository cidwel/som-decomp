.setcpu "65816"
.segment "CODE"
.org $3B8E
map_control_0d3b8e:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
