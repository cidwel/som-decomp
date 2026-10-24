.setcpu "65816"
.segment "CODE"
.org $7BB1
map_control_0c7bb1:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
