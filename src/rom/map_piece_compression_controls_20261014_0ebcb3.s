.setcpu "65816"
.segment "CODE"
.org $BCB3
map_control_0ebcb3:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
