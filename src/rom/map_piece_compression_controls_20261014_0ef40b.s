.setcpu "65816"
.segment "CODE"
.org $F40B
map_control_0ef40b:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
