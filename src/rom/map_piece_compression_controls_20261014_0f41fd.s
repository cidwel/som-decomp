.setcpu "65816"
.segment "CODE"
.org $41FD
map_control_0f41fd:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
