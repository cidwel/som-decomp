.setcpu "65816"
.segment "CODE"
.org $DD16
map_control_0ddd16:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
