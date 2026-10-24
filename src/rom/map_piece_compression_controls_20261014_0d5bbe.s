.setcpu "65816"
.segment "CODE"
.org $5BBE
map_control_0d5bbe:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
