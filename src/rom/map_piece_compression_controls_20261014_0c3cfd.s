.setcpu "65816"
.segment "CODE"
.org $3CFD
map_control_0c3cfd:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $E1 ; previous-row copy count
