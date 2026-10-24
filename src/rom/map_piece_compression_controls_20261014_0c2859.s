.setcpu "65816"
.segment "CODE"
.org $2859
map_control_0c2859:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
