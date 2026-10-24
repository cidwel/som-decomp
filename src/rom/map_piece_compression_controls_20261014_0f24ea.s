.setcpu "65816"
.segment "CODE"
.org $24EA
map_control_0f24ea:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
