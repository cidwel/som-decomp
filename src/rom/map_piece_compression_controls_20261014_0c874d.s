.setcpu "65816"
.segment "CODE"
.org $874D
map_control_0c874d:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
