.setcpu "65816"
.segment "CODE"
.org $944C
map_control_0e944c:
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
