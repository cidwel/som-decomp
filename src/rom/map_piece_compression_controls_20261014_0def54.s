.setcpu "65816"
.segment "CODE"
.org $EF54
map_control_0def54:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
