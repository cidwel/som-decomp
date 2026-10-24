.setcpu "65816"
.segment "CODE"
.org $888A
map_control_0c888a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
