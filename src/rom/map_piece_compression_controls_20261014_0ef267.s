.setcpu "65816"
.segment "CODE"
.org $F267
map_control_0ef267:
    .byte $EC ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
