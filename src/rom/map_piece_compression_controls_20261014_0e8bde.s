.setcpu "65816"
.segment "CODE"
.org $8BDE
map_control_0e8bde:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
