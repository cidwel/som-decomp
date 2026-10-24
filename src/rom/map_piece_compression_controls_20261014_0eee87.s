.setcpu "65816"
.segment "CODE"
.org $EE87
map_control_0eee87:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
