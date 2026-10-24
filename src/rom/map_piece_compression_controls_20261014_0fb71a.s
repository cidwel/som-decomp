.setcpu "65816"
.segment "CODE"
.org $B71A
map_control_0fb71a:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
