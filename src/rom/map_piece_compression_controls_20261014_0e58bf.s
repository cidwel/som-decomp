.setcpu "65816"
.segment "CODE"
.org $58BF
map_control_0e58bf:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
