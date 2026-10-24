.setcpu "65816"
.segment "CODE"
.org $8784
map_control_0d8784:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
