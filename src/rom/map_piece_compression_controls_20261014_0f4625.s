.setcpu "65816"
.segment "CODE"
.org $4625
map_control_0f4625:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
