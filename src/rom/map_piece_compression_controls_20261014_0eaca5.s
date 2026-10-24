.setcpu "65816"
.segment "CODE"
.org $ACA5
map_control_0eaca5:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
