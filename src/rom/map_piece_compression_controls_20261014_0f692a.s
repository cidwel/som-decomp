.setcpu "65816"
.segment "CODE"
.org $692A
map_control_0f692a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
