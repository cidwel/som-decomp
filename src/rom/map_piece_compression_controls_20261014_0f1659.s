.setcpu "65816"
.segment "CODE"
.org $1659
map_control_0f1659:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
