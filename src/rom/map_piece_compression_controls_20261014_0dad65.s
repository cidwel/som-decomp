.setcpu "65816"
.segment "CODE"
.org $AD65
map_control_0dad65:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
