.setcpu "65816"
.segment "CODE"
.org $D16D
map_control_0dd16d:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
