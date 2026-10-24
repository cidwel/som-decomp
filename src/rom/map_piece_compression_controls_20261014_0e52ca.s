.setcpu "65816"
.segment "CODE"
.org $52CA
map_control_0e52ca:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
