.setcpu "65816"
.segment "CODE"
.org $03A1
map_control_0e03a1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
