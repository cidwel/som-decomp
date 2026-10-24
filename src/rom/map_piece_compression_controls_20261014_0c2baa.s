.setcpu "65816"
.segment "CODE"
.org $2BAA
map_control_0c2baa:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
