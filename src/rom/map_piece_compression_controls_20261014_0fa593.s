.setcpu "65816"
.segment "CODE"
.org $A593
map_control_0fa593:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
