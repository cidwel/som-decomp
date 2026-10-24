.setcpu "65816"
.segment "CODE"
.org $EA5C
map_control_0dea5c:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
