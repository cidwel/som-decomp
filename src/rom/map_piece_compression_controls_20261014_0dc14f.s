.setcpu "65816"
.segment "CODE"
.org $C14F
map_control_0dc14f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
