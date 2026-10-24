.setcpu "65816"
.segment "CODE"
.org $FB71
map_control_0cfb71:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
