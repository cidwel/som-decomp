.setcpu "65816"
.segment "CODE"
.org $B95F
map_control_0fb95f:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
