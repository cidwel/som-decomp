.setcpu "65816"
.segment "CODE"
.org $28F7
map_control_0c28f7:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
