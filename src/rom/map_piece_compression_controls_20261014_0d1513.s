.setcpu "65816"
.segment "CODE"
.org $1513
map_control_0d1513:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
