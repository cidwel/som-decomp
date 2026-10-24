.setcpu "65816"
.segment "CODE"
.org $D1AD
map_control_0ed1ad:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
