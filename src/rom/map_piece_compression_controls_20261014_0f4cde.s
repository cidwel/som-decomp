.setcpu "65816"
.segment "CODE"
.org $4CDE
map_control_0f4cde:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
