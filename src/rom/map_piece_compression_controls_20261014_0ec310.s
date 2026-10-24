.setcpu "65816"
.segment "CODE"
.org $C310
map_control_0ec310:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
