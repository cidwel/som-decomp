.setcpu "65816"
.segment "CODE"
.org $1179
map_control_0c1179:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
