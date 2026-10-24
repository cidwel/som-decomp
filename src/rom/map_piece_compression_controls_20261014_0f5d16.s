.setcpu "65816"
.segment "CODE"
.org $5D16
map_control_0f5d16:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
