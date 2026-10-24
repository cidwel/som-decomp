.setcpu "65816"
.segment "CODE"
.org $B3B8
map_control_0eb3b8:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
