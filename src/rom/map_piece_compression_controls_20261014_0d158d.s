.setcpu "65816"
.segment "CODE"
.org $158D
map_control_0d158d:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
