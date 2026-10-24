.setcpu "65816"
.segment "CODE"
.org $D7B7
map_control_0ed7b7:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
