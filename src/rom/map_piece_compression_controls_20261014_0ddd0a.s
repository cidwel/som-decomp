.setcpu "65816"
.segment "CODE"
.org $DD0A
map_control_0ddd0a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
