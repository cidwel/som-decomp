.setcpu "65816"
.segment "CODE"
.org $BD50
map_control_0dbd50:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
