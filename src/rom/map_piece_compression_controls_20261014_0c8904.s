.setcpu "65816"
.segment "CODE"
.org $8904
map_control_0c8904:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
