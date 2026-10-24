.setcpu "65816"
.segment "CODE"
.org $50DA
map_control_0f50da:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
