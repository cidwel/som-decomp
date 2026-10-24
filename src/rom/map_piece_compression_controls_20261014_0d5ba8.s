.setcpu "65816"
.segment "CODE"
.org $5BA8
map_control_0d5ba8:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
