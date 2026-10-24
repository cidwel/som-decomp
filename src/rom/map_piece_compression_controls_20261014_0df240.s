.setcpu "65816"
.segment "CODE"
.org $F240
map_control_0df240:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
