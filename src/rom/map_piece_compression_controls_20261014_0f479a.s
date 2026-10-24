.setcpu "65816"
.segment "CODE"
.org $479A
map_control_0f479a:
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
