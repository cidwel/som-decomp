.setcpu "65816"
.segment "CODE"
.org $B967
map_control_0fb967:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5B ; row-distance/count
