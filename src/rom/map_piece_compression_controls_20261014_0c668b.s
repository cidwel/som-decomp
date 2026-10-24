.setcpu "65816"
.segment "CODE"
.org $668B
map_control_0c668b:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
