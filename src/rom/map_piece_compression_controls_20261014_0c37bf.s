.setcpu "65816"
.segment "CODE"
.org $37BF
map_control_0c37bf:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
