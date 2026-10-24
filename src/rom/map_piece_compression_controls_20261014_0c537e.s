.setcpu "65816"
.segment "CODE"
.org $537E
map_control_0c537e:
    .byte $EF ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
