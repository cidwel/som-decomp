.setcpu "65816"
.segment "CODE"
.org $AF22
map_control_0eaf22:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
