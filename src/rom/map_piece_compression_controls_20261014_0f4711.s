.setcpu "65816"
.segment "CODE"
.org $4711
map_control_0f4711:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
