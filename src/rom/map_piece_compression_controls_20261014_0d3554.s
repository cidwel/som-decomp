.setcpu "65816"
.segment "CODE"
.org $3554
map_control_0d3554:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
