.setcpu "65816"
.segment "CODE"
.org $51D6
map_control_0d51d6:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
