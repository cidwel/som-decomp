.setcpu "65816"
.segment "CODE"
.org $2AD9
map_control_0f2ad9:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
