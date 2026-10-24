.setcpu "65816"
.segment "CODE"
.org $3F9A
map_control_0f3f9a:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
