.setcpu "65816"
.segment "CODE"
.org $1BD0
map_control_0d1bd0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
