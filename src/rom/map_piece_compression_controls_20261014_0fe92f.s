.setcpu "65816"
.segment "CODE"
.org $E92F
map_control_0fe92f:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
