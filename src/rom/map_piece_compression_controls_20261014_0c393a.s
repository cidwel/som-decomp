.setcpu "65816"
.segment "CODE"
.org $393A
map_control_0c393a:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
