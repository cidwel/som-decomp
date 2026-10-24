.setcpu "65816"
.segment "CODE"
.org $3240
map_control_0d3240:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
