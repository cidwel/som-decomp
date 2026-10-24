.setcpu "65816"
.segment "CODE"
.org $349D
map_control_0f349d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
