.setcpu "65816"
.segment "CODE"
.org $3BA6
map_control_0c3ba6:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
