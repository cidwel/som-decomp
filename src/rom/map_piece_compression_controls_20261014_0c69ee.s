.setcpu "65816"
.segment "CODE"
.org $69EE
map_control_0c69ee:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
