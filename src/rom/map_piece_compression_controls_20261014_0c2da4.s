.setcpu "65816"
.segment "CODE"
.org $2DA4
map_control_0c2da4:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
