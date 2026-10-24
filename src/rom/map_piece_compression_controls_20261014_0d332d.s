.setcpu "65816"
.segment "CODE"
.org $332D
map_control_0d332d:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
