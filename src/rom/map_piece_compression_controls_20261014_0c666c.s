.setcpu "65816"
.segment "CODE"
.org $666C
map_control_0c666c:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
