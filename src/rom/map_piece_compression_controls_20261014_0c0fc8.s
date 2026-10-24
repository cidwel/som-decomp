.setcpu "65816"
.segment "CODE"
.org $0FC8
map_control_0c0fc8:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
