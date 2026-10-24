.setcpu "65816"
.segment "CODE"
.org $8E44
map_control_0e8e44:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
