.setcpu "65816"
.segment "CODE"
.org $28B9
map_control_0c28b9:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
