.setcpu "65816"
.segment "CODE"
.org $5605
map_control_0d5605:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
