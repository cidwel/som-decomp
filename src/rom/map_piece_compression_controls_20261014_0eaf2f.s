.setcpu "65816"
.segment "CODE"
.org $AF2F
map_control_0eaf2f:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
