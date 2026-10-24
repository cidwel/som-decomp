.setcpu "65816"
.segment "CODE"
.org $6BFB
map_control_0e6bfb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
