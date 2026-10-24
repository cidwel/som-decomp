.setcpu "65816"
.segment "CODE"
.org $50FB
map_control_0d50fb:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
