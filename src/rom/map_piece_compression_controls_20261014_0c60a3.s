.setcpu "65816"
.segment "CODE"
.org $60A3
map_control_0c60a3:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
