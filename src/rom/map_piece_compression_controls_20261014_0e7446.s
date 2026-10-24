.setcpu "65816"
.segment "CODE"
.org $7446
map_control_0e7446:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
