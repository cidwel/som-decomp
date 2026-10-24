.setcpu "65816"
.segment "CODE"
.org $ABA0
map_control_0eaba0:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
