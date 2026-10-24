.setcpu "65816"
.segment "CODE"
.org $2BAE
map_control_0c2bae:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
