.setcpu "65816"
.segment "CODE"
.org $7E5A
map_control_0c7e5a:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
