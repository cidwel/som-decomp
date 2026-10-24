.setcpu "65816"
.segment "CODE"
.org $4088
map_control_0c4088:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
