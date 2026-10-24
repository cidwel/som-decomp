.setcpu "65816"
.segment "CODE"
.org $C132
map_control_0ec132:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
