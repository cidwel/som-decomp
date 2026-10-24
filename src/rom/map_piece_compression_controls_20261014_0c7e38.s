.setcpu "65816"
.segment "CODE"
.org $7E38
map_control_0c7e38:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
