.setcpu "65816"
.segment "CODE"
.org $DA96
map_control_0dda96:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
