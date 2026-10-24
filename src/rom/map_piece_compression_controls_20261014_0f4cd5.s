.setcpu "65816"
.segment "CODE"
.org $4CD5
map_control_0f4cd5:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
