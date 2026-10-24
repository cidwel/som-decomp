.setcpu "65816"
.segment "CODE"
.org $8BE9
map_control_0e8be9:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
