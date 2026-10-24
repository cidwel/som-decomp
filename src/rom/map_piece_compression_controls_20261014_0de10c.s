.setcpu "65816"
.segment "CODE"
.org $E10C
map_control_0de10c:
    .byte $EC ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
