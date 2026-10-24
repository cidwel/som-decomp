.setcpu "65816"
.segment "CODE"
.org $EEE3
map_control_0eeee3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
