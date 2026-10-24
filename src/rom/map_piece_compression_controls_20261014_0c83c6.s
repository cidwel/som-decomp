.setcpu "65816"
.segment "CODE"
.org $83C6
map_control_0c83c6:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E2 ; previous-row copy count
