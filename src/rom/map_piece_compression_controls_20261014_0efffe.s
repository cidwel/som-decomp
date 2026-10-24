.setcpu "65816"
.segment "CODE"
.org $FFFE
map_control_0efffe:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
