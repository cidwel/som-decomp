.setcpu "65816"
.segment "CODE"
.org $880B
map_control_0e880b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
