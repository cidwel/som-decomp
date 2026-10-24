.setcpu "65816"
.segment "CODE"
.org $5E4A
map_control_0d5e4a:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
