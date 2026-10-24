.setcpu "65816"
.segment "CODE"
.org $B51A
map_control_0db51a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
