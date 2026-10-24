.setcpu "65816"
.segment "CODE"
.org $4209
map_control_0c4209:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
