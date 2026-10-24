.setcpu "65816"
.segment "CODE"
.org $91A0
map_control_0c91a0:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
