.setcpu "65816"
.segment "CODE"
.org $DD4F
map_control_0fdd4f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $79 ; row-distance/count
