.setcpu "65816"
.segment "CODE"
.org $8BF5
map_control_0e8bf5:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
