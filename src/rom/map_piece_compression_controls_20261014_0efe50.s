.setcpu "65816"
.segment "CODE"
.org $FE50
map_control_0efe50:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
