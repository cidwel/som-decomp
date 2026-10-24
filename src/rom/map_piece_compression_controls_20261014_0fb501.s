.setcpu "65816"
.segment "CODE"
.org $B501
map_control_0fb501:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
