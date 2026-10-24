.setcpu "65816"
.segment "CODE"
.org $D0E9
map_control_0ed0e9:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
