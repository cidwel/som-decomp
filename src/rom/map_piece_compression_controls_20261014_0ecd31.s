.setcpu "65816"
.segment "CODE"
.org $CD31
map_control_0ecd31:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
