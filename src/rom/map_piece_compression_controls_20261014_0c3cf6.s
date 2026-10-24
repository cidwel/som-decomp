.setcpu "65816"
.segment "CODE"
.org $3CF6
map_control_0c3cf6:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
