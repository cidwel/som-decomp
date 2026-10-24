.setcpu "65816"
.segment "CODE"
.org $4B9E
map_control_0e4b9e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
