.setcpu "65816"
.segment "CODE"
.org $B463
map_control_0eb463:
    .byte $EC ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
