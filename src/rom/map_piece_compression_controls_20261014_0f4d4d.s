.setcpu "65816"
.segment "CODE"
.org $4D4D
map_control_0f4d4d:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
