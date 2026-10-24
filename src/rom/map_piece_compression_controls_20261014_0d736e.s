.setcpu "65816"
.segment "CODE"
.org $736E
map_control_0d736e:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
