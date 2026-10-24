.setcpu "65816"
.segment "CODE"
.org $F40E
map_control_0ef40e:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
