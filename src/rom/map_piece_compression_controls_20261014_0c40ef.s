.setcpu "65816"
.segment "CODE"
.org $40EF
map_control_0c40ef:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
