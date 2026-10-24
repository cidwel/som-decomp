.setcpu "65816"
.segment "CODE"
.org $DD0D
map_control_0fdd0d:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
