.setcpu "65816"
.segment "CODE"
.org $1BDF
map_control_0d1bdf:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
