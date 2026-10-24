.setcpu "65816"
.segment "CODE"
.org $7BF4
map_control_0c7bf4:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
