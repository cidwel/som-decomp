.setcpu "65816"
.segment "CODE"
.org $B7ED
map_control_0fb7ed:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
