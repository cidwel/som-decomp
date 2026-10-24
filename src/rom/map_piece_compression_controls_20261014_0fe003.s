.setcpu "65816"
.segment "CODE"
.org $E003
map_control_0fe003:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
