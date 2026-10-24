.setcpu "65816"
.segment "CODE"
.org $C210
map_control_0ec210:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
