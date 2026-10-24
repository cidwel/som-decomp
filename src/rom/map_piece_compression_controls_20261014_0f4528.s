.setcpu "65816"
.segment "CODE"
.org $4528
map_control_0f4528:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
