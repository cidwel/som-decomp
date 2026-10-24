.setcpu "65816"
.segment "CODE"
.org $AE6C
map_control_0fae6c:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
