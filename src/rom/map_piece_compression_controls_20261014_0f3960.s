.setcpu "65816"
.segment "CODE"
.org $3960
map_control_0f3960:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
