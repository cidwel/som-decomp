.setcpu "65816"
.segment "CODE"
.org $70F3
map_control_0f70f3:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
