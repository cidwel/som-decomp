.setcpu "65816"
.segment "CODE"
.org $E75A
map_control_0fe75a:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
