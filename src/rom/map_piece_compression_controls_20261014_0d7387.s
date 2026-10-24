.setcpu "65816"
.segment "CODE"
.org $7387
map_control_0d7387:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
