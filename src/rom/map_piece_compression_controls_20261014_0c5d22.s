.setcpu "65816"
.segment "CODE"
.org $5D22
map_control_0c5d22:
    .byte $E8 ; backreference distance high bits
    .byte $41 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
