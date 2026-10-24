.setcpu "65816"
.segment "CODE"
.org $C42C
map_control_0dc42c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
