.setcpu "65816"
.segment "CODE"
.org $1635
map_control_0d1635:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
