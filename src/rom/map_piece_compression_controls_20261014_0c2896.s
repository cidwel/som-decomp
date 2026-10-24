.setcpu "65816"
.segment "CODE"
.org $2896
map_control_0c2896:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
