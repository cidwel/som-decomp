.setcpu "65816"
.segment "CODE"
.org $571C
map_control_0f571c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
