.setcpu "65816"
.segment "CODE"
.org $110B
map_control_0e110b:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
