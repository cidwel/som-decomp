.setcpu "65816"
.segment "CODE"
.org $28A7
map_control_0c28a7:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
