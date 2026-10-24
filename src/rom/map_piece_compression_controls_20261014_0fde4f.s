.setcpu "65816"
.segment "CODE"
.org $DE4F
map_control_0fde4f:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
