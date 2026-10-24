.setcpu "65816"
.segment "CODE"
.org $5FE8
map_control_0d5fe8:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
