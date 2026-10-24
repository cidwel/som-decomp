.setcpu "65816"
.segment "CODE"
.org $3824
map_control_0c3824:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
