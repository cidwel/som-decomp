.setcpu "65816"
.segment "CODE"
.org $7C16
map_control_0c7c16:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
