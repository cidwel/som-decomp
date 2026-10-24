.setcpu "65816"
.segment "CODE"
.org $B133
map_control_0db133:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
