.setcpu "65816"
.segment "CODE"
.org $A48A
map_control_0da48a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
