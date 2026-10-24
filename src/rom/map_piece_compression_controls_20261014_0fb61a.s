.setcpu "65816"
.segment "CODE"
.org $B61A
map_control_0fb61a:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
