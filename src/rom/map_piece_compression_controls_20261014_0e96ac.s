.setcpu "65816"
.segment "CODE"
.org $96AC
map_control_0e96ac:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
