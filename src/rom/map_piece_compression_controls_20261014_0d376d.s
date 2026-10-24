.setcpu "65816"
.segment "CODE"
.org $376D
map_control_0d376d:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
