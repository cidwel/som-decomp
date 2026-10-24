.setcpu "65816"
.segment "CODE"
.org $75EA
map_control_0e75ea:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
