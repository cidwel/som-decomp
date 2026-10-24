.setcpu "65816"
.segment "CODE"
.org $4741
map_control_0f4741:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
