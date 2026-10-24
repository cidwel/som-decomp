.setcpu "65816"
.segment "CODE"
.org $6912
map_control_0e6912:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
