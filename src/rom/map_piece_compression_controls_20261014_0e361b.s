.setcpu "65816"
.segment "CODE"
.org $361B
map_control_0e361b:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
