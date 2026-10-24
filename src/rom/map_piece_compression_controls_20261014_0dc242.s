.setcpu "65816"
.segment "CODE"
.org $C242
map_control_0dc242:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
