.setcpu "65816"
.segment "CODE"
.org $23B6
map_control_0d23b6:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
