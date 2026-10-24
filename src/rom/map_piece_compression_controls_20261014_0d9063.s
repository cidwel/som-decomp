.setcpu "65816"
.segment "CODE"
.org $9063
map_control_0d9063:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
