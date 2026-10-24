.setcpu "65816"
.segment "CODE"
.org $01FE
map_control_0f01fe:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
