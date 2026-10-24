.setcpu "65816"
.segment "CODE"
.org $8B0F
map_control_0f8b0f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
