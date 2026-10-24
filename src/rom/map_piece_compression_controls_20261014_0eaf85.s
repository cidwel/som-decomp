.setcpu "65816"
.segment "CODE"
.org $AF85
map_control_0eaf85:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
