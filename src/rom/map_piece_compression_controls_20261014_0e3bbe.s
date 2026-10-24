.setcpu "65816"
.segment "CODE"
.org $3BBE
map_control_0e3bbe:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
