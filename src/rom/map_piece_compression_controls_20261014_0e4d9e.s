.setcpu "65816"
.segment "CODE"
.org $4D9E
map_control_0e4d9e:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
