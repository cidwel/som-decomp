.setcpu "65816"
.segment "CODE"
.org $AE41
map_control_0fae41:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
