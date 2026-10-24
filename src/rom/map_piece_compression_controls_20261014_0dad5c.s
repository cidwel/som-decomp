.setcpu "65816"
.segment "CODE"
.org $AD5C
map_control_0dad5c:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
