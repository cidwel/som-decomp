.setcpu "65816"
.segment "CODE"
.org $1ACB
map_control_0f1acb:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
