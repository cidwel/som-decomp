.setcpu "65816"
.segment "CODE"
.org $90B4
map_control_0c90b4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
