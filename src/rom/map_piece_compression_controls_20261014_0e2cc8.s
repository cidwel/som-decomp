.setcpu "65816"
.segment "CODE"
.org $2CC8
map_control_0e2cc8:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
