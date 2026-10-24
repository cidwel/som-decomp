.setcpu "65816"
.segment "CODE"
.org $16E1
map_control_0f16e1:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
