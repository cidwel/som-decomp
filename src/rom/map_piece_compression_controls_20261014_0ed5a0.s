.setcpu "65816"
.segment "CODE"
.org $D5A0
map_control_0ed5a0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
