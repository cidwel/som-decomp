.setcpu "65816"
.segment "CODE"
.org $672B
map_control_0c672b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
