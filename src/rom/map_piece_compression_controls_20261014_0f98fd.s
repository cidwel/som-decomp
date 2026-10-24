.setcpu "65816"
.segment "CODE"
.org $98FD
map_control_0f98fd:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
