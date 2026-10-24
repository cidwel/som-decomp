.setcpu "65816"
.segment "CODE"
.org $191F
map_control_0e191f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
