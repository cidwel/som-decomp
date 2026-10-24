.setcpu "65816"
.segment "CODE"
.org $58F8
map_control_0d58f8:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
