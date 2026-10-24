.setcpu "65816"
.segment "CODE"
.org $AD69
map_control_0fad69:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
