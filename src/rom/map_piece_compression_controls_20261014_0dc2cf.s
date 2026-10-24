.setcpu "65816"
.segment "CODE"
.org $C2CF
map_control_0dc2cf:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
