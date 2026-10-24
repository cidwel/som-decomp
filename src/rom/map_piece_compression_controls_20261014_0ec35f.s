.setcpu "65816"
.segment "CODE"
.org $C35F
map_control_0ec35f:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
