.setcpu "65816"
.segment "CODE"
.org $5DB0
map_control_0e5db0:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
