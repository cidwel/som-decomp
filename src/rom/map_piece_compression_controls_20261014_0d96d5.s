.setcpu "65816"
.segment "CODE"
.org $96D5
map_control_0d96d5:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
