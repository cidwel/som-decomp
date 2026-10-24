.setcpu "65816"
.segment "CODE"
.org $E644
map_control_0fe644:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
