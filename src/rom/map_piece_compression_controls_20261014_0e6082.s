.setcpu "65816"
.segment "CODE"
.org $6082
map_control_0e6082:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
