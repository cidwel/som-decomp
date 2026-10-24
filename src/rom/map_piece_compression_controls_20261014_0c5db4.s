.setcpu "65816"
.segment "CODE"
.org $5DB4
map_control_0c5db4:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
