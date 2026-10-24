.setcpu "65816"
.segment "CODE"
.org $39A4
map_control_0d39a4:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
