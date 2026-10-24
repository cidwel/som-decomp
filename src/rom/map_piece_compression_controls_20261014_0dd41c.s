.setcpu "65816"
.segment "CODE"
.org $D41C
map_control_0dd41c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
