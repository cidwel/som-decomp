.setcpu "65816"
.segment "CODE"
.org $5DB0
map_control_0f5db0:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
