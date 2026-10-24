.setcpu "65816"
.segment "CODE"
.org $E687
map_control_0fe687:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
