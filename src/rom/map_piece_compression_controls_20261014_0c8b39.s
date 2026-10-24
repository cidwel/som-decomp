.setcpu "65816"
.segment "CODE"
.org $8B39
map_control_0c8b39:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
