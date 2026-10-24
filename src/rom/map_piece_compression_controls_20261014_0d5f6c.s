.setcpu "65816"
.segment "CODE"
.org $5F6C
map_control_0d5f6c:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
