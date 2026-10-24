.setcpu "65816"
.segment "CODE"
.org $72D0
map_control_0e72d0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
