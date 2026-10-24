.setcpu "65816"
.segment "CODE"
.org $5CC1
map_control_0e5cc1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
