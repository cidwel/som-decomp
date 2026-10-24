.setcpu "65816"
.segment "CODE"
.org $E8E9
map_control_0fe8e9:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
