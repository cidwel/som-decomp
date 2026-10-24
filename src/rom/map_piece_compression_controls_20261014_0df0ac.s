.setcpu "65816"
.segment "CODE"
.org $F0AC
map_control_0df0ac:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
