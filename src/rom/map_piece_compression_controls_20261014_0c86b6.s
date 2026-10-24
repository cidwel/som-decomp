.setcpu "65816"
.segment "CODE"
.org $86B6
map_control_0c86b6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
