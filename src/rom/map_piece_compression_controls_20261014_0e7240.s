.setcpu "65816"
.segment "CODE"
.org $7240
map_control_0e7240:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
