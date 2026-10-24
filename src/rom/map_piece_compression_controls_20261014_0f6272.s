.setcpu "65816"
.segment "CODE"
.org $6272
map_control_0f6272:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $54 ; distance low bit/count
