.setcpu "65816"
.segment "CODE"
.org $8F16
map_control_0d8f16:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
