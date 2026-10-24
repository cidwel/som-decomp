.setcpu "65816"
.segment "CODE"
.org $E9CA
map_control_0de9ca:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
