.setcpu "65816"
.segment "CODE"
.org $8F59
map_control_0d8f59:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
