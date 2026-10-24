.setcpu "65816"
.segment "CODE"
.org $3785
map_control_0f3785:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
