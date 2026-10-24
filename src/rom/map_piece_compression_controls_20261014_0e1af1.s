.setcpu "65816"
.segment "CODE"
.org $1AF1
map_control_0e1af1:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
