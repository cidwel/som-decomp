.setcpu "65816"
.segment "CODE"
.org $9F71
map_control_0d9f71:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
