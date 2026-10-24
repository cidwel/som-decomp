.setcpu "65816"
.segment "CODE"
.org $CCCE
map_control_0fccce:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
