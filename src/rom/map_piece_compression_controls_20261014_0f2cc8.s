.setcpu "65816"
.segment "CODE"
.org $2CC8
map_control_0f2cc8:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
