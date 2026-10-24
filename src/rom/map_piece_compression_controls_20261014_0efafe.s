.setcpu "65816"
.segment "CODE"
.org $FAFE
map_control_0efafe:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
