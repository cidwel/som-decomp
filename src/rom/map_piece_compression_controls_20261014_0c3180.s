.setcpu "65816"
.segment "CODE"
.org $3180
map_control_0c3180:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
