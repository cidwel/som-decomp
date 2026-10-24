.setcpu "65816"
.segment "CODE"
.org $988D
map_control_0f988d:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
