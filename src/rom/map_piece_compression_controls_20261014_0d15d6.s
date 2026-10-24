.setcpu "65816"
.segment "CODE"
.org $15D6
map_control_0d15d6:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
