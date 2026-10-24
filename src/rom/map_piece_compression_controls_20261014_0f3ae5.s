.setcpu "65816"
.segment "CODE"
.org $3AE5
map_control_0f3ae5:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
