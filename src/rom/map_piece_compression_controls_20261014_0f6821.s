.setcpu "65816"
.segment "CODE"
.org $6821
map_control_0f6821:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
