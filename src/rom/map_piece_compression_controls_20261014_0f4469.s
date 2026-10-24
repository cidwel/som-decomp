.setcpu "65816"
.segment "CODE"
.org $4469
map_control_0f4469:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
