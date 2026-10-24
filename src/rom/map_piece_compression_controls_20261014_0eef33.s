.setcpu "65816"
.segment "CODE"
.org $EF33
map_control_0eef33:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
