.setcpu "65816"
.segment "CODE"
.org $5DB5
map_control_0f5db5:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
