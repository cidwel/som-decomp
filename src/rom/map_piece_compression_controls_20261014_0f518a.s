.setcpu "65816"
.segment "CODE"
.org $518A
map_control_0f518a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
