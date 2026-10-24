.setcpu "65816"
.segment "CODE"
.org $936E
map_control_0d936e:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
