.setcpu "65816"
.segment "CODE"
.org $7BB7
map_control_0c7bb7:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
