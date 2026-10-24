.setcpu "65816"
.segment "CODE"
.org $8AF4
map_control_0c8af4:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
