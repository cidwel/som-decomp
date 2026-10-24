.setcpu "65816"
.segment "CODE"
.org $AE33
map_control_0fae33:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
