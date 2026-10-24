.setcpu "65816"
.segment "CODE"
.org $4CD1
map_control_0f4cd1:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
