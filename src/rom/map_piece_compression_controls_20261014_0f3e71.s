.setcpu "65816"
.segment "CODE"
.org $3E71
map_control_0f3e71:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
