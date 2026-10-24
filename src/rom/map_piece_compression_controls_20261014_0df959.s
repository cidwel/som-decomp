.setcpu "65816"
.segment "CODE"
.org $F959
map_control_0df959:
    .byte $F7 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
