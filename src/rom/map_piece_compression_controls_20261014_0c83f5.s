.setcpu "65816"
.segment "CODE"
.org $83F5
map_control_0c83f5:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
