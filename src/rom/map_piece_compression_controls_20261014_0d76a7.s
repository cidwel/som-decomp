.setcpu "65816"
.segment "CODE"
.org $76A7
map_control_0d76a7:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
