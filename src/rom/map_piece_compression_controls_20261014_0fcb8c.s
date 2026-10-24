.setcpu "65816"
.segment "CODE"
.org $CB8C
map_control_0fcb8c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
