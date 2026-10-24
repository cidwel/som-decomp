.setcpu "65816"
.segment "CODE"
.org $5625
map_control_0f5625:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
