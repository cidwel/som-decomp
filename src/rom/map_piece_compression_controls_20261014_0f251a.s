.setcpu "65816"
.segment "CODE"
.org $251A
map_control_0f251a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
