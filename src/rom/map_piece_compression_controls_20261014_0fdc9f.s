.setcpu "65816"
.segment "CODE"
.org $DC9F
map_control_0fdc9f:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
