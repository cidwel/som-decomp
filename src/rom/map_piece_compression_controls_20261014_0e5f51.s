.setcpu "65816"
.segment "CODE"
.org $5F51
map_control_0e5f51:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
