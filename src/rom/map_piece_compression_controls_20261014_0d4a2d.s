.setcpu "65816"
.segment "CODE"
.org $4A2D
map_control_0d4a2d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
