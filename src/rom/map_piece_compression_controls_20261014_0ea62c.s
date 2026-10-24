.setcpu "65816"
.segment "CODE"
.org $A62C
map_control_0ea62c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
