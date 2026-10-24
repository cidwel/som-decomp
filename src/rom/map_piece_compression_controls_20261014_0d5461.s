.setcpu "65816"
.segment "CODE"
.org $5461
map_control_0d5461:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
