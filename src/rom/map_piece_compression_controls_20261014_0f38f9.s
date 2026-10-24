.setcpu "65816"
.segment "CODE"
.org $38F9
map_control_0f38f9:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
