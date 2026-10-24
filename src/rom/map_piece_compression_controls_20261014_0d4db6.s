.setcpu "65816"
.segment "CODE"
.org $4DB6
map_control_0d4db6:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
