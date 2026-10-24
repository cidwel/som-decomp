.setcpu "65816"
.segment "CODE"
.org $8B13
map_control_0c8b13:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
