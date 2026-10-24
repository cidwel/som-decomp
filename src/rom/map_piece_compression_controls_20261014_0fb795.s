.setcpu "65816"
.segment "CODE"
.org $B795
map_control_0fb795:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
