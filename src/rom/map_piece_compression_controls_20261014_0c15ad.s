.setcpu "65816"
.segment "CODE"
.org $15AD
map_control_0c15ad:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
