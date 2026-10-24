.setcpu "65816"
.segment "CODE"
.org $B67C
map_control_0fb67c:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
