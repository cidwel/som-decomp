.setcpu "65816"
.segment "CODE"
.org $28CD
map_control_0f28cd:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
