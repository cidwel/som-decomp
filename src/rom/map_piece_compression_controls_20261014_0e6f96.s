.setcpu "65816"
.segment "CODE"
.org $6F96
map_control_0e6f96:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
