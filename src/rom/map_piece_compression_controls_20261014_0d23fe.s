.setcpu "65816"
.segment "CODE"
.org $23FE
map_control_0d23fe:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
