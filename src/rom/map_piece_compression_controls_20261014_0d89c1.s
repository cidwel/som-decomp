.setcpu "65816"
.segment "CODE"
.org $89C1
map_control_0d89c1:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
