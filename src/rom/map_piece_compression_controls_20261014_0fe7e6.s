.setcpu "65816"
.segment "CODE"
.org $E7E6
map_control_0fe7e6:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
