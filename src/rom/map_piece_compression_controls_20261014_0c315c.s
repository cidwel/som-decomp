.setcpu "65816"
.segment "CODE"
.org $315C
map_control_0c315c:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
