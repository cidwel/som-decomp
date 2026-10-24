.setcpu "65816"
.segment "CODE"
.org $CA9E
map_control_0eca9e:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
