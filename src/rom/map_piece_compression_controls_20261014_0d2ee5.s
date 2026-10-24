.setcpu "65816"
.segment "CODE"
.org $2EE5
map_control_0d2ee5:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
