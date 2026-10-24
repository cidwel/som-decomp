.setcpu "65816"
.segment "CODE"
.org $FE67
map_control_0efe67:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
