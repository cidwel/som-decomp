.setcpu "65816"
.segment "CODE"
.org $58A7
map_control_0d58a7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
