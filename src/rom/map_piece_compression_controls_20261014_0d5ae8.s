.setcpu "65816"
.segment "CODE"
.org $5AE8
map_control_0d5ae8:
    .byte $EC ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
