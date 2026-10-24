.setcpu "65816"
.segment "CODE"
.org $76AC
map_control_0c76ac:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
