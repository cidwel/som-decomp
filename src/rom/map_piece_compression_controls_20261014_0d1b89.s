.setcpu "65816"
.segment "CODE"
.org $1B89
map_control_0d1b89:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
