.setcpu "65816"
.segment "CODE"
.org $24F4
map_control_0c24f4:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
