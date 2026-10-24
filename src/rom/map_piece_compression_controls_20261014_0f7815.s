.setcpu "65816"
.segment "CODE"
.org $7815
map_control_0f7815:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $31 ; distance low bit/count
