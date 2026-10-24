.setcpu "65816"
.segment "CODE"
.org $0089
map_control_0f0089:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
