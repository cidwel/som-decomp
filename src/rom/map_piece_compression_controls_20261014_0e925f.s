.setcpu "65816"
.segment "CODE"
.org $925F
map_control_0e925f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
