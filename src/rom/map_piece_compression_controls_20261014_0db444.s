.setcpu "65816"
.segment "CODE"
.org $B444
map_control_0db444:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
