.setcpu "65816"
.segment "CODE"
.org $4D0C
map_control_0f4d0c:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
