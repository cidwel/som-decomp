.setcpu "65816"
.segment "CODE"
.org $947B
map_control_0d947b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
