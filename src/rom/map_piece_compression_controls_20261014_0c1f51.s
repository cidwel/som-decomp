.setcpu "65816"
.segment "CODE"
.org $1F51
map_control_0c1f51:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
