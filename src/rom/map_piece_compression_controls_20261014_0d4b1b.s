.setcpu "65816"
.segment "CODE"
.org $4B1B
map_control_0d4b1b:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
