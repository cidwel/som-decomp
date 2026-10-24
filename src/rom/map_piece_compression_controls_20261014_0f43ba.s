.setcpu "65816"
.segment "CODE"
.org $43BA
map_control_0f43ba:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
