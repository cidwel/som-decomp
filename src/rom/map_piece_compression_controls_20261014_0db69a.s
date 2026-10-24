.setcpu "65816"
.segment "CODE"
.org $B69A
map_control_0db69a:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
