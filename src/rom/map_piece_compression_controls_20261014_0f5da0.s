.setcpu "65816"
.segment "CODE"
.org $5DA0
map_control_0f5da0:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
