.setcpu "65816"
.segment "CODE"
.org $3EF6
map_control_0c3ef6:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
