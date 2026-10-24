.setcpu "65816"
.segment "CODE"
.org $5C00
map_control_0f5c00:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
