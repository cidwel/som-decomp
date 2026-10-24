.setcpu "65816"
.segment "CODE"
.org $BDAC
map_control_0fbdac:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
