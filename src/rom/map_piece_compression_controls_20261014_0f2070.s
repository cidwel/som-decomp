.setcpu "65816"
.segment "CODE"
.org $2070
map_control_0f2070:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
