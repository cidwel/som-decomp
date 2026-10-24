.setcpu "65816"
.segment "CODE"
.org $023B
map_control_0f023b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
