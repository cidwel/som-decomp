.setcpu "65816"
.segment "CODE"
.org $58C6
map_control_0d58c6:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
