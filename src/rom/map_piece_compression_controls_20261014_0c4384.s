.setcpu "65816"
.segment "CODE"
.org $4384
map_control_0c4384:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
