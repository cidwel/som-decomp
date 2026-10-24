.setcpu "65816"
.segment "CODE"
.org $F2A2
map_control_0ff2a2:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
