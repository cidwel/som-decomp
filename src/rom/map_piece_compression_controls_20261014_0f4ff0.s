.setcpu "65816"
.segment "CODE"
.org $4FF0
map_control_0f4ff0:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
