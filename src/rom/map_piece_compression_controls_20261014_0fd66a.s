.setcpu "65816"
.segment "CODE"
.org $D66A
map_control_0fd66a:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
