.setcpu "65816"
.segment "CODE"
.org $ADA4
map_control_0dada4:
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
