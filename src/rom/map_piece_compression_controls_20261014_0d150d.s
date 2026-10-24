.setcpu "65816"
.segment "CODE"
.org $150D
map_control_0d150d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
