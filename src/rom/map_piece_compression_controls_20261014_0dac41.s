.setcpu "65816"
.segment "CODE"
.org $AC41
map_control_0dac41:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
