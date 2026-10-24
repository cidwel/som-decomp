.setcpu "65816"
.segment "CODE"
.org $2AFE
map_control_0c2afe:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
