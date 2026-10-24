.setcpu "65816"
.segment "CODE"
.org $AE5B
map_control_0fae5b:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
