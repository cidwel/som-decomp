.setcpu "65816"
.segment "CODE"
.org $2444
map_control_0d2444:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
