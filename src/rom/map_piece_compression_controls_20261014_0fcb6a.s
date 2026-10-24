.setcpu "65816"
.segment "CODE"
.org $CB6A
map_control_0fcb6a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
