.setcpu "65816"
.segment "CODE"
.org $AEC9
map_control_0eaec9:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
