.setcpu "65816"
.segment "CODE"
.org $4C4F
map_control_0f4c4f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
