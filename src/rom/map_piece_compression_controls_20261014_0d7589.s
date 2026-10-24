.setcpu "65816"
.segment "CODE"
.org $7589
map_control_0d7589:
    .byte $E0 ; previous-row copy escape
    .byte $CC ; row-distance/count
