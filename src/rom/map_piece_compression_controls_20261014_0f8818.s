.setcpu "65816"
.segment "CODE"
.org $8818
map_control_0f8818:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
