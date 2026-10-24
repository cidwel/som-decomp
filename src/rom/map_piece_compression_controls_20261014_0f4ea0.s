.setcpu "65816"
.segment "CODE"
.org $4EA0
map_control_0f4ea0:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
