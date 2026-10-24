.setcpu "65816"
.segment "CODE"
.org $AEE1
map_control_0faee1:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
