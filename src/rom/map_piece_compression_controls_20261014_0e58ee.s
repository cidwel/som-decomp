.setcpu "65816"
.segment "CODE"
.org $58EE
map_control_0e58ee:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
