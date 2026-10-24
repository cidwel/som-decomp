.setcpu "65816"
.segment "CODE"
.org $5981
map_control_0d5981:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
