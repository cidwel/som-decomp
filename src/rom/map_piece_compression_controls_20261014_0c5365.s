.setcpu "65816"
.segment "CODE"
.org $5365
map_control_0c5365:
    .byte $EF ; backreference distance high bits
    .byte $98 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
