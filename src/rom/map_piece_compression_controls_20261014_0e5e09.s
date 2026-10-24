.setcpu "65816"
.segment "CODE"
.org $5E09
map_control_0e5e09:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
